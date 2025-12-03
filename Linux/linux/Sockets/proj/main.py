import socket
import threading
import tkinter as tk
from tkinter import filedialog, scrolledtext
import os

class ChatApp:
    def __init__(self, master, mode, host, port):
        self.master = master
        self.mode = mode
        self.host = host
        self.port = int(port)
        self.sock = None
        self.conn = None

        master.title(f"Chat {mode.capitalize()}")
        master.geometry("600x500")

        # Chat display
        self.chat_area = scrolledtext.ScrolledText(master, state='disabled')
        self.chat_area.pack(expand=True, fill='both', padx=5, pady=5)

        # Entry frame
        entry_frame = tk.Frame(master)
        entry_frame.pack(fill='x', padx=5, pady=5)

        self.entry = tk.Entry(entry_frame)
        self.entry.pack(side='left', expand=True, fill='x', padx=(0,5))
        self.entry.bind("<Return>", lambda event: self.send_message())

        send_btn = tk.Button(entry_frame, text="Send", command=self.send_message)
        send_btn.pack(side='left', padx=(0,5))

        file_btn = tk.Button(entry_frame, text="Send File", command=self.send_file_dialog)
        file_btn.pack(side='left')

        # Networking thread
        threading.Thread(target=self.start_network, daemon=True).start()

    def start_network(self):
        if self.mode == 'server':
            self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            self.sock.bind((self.host, self.port))
            self.sock.listen(1)
            self.add_chat("[+] Waiting for client...")
            self.conn, addr = self.sock.accept()
            self.add_chat(f"[+] Client connected from {addr}")
        else:
            self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            try:
                self.sock.connect((self.host, self.port))
                self.conn = self.sock
                self.add_chat(f"[+] Connected to server {self.host}:{self.port}")
            except Exception as e:
                self.add_chat(f"[!] Connection failed: {e}")
                return

        threading.Thread(target=self.receive_messages, daemon=True).start()

    def send_message(self):
        msg = self.entry.get()
        if not msg:
            return
        try:
            self.conn.sendall(msg.encode('utf-8'))
            self.add_chat(f"You: {msg}")
            self.entry.delete(0, tk.END)
        except Exception as e:
            self.add_chat(f"[!] Send failed: {e}")

    def receive_messages(self):
        while True:
            try:
                data = self.conn.recv(4096)
                if not data:
                    self.add_chat("[!] Connection closed")
                    break

                # Check if it's a file header
                if data.startswith(b"FILE:"):
                    filename = data[5:].decode()
                    self.receive_file(filename)
                else:
                    self.add_chat(f"Peer: {data.decode(errors='replace')}")
            except Exception as e:
                self.add_chat(f"[!] Receive error: {e}")
                break

    def send_file_dialog(self):
        filepath = filedialog.askopenfilename()
        if not filepath:
            return
        filename = os.path.basename(filepath)
        try:
            self.conn.sendall(f"FILE:{filename}".encode())

            with open(filepath, 'rb') as f:
                while True:
                    chunk = f.read(4096)
                    if not chunk:
                        break
                    self.conn.sendall(chunk)

            self.conn.sendall(b"EOF")
            self.add_chat(f"[+] Sent file: {filename}")
        except Exception as e:
            self.add_chat(f"[!] File send failed: {e}")

    def receive_file(self, filename):
        save_path = f"received_{filename}"
        try:
            with open(save_path, 'wb') as f:
                while True:
                    chunk = self.conn.recv(4096)
                    if chunk == b"EOF":
                        break
                    f.write(chunk)
            self.add_chat(f"[+] Received file: {save_path}")
        except Exception as e:
            self.add_chat(f"[!] File receive failed: {e}")

    def add_chat(self, msg):
        self.chat_area.configure(state='normal')
        self.chat_area.insert(tk.END, msg + "\n")
        self.chat_area.configure(state='disabled')
        self.chat_area.yview(tk.END)

if __name__ == "__main__":
    import sys
    if len(sys.argv) < 4:
        print("Usage: python3 main.py <server|client> <host> <port>")
        sys.exit(1)

    mode, host, port = sys.argv[1], sys.argv[2], sys.argv[3]
    root = tk.Tk()
    app = ChatApp(root, mode, host, port)
    root.mainloop()

