FROM ubuntu:22.04

RUN apt update && apt install -y gcc nano

COPY hello.c /hello.c

RUN gcc hello.c -o hello

CMD ["/hello"]
