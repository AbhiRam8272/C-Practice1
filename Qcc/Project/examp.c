#include <stdio.h>
#include <stdint.h>
#include <string.h>

// Macros for bit manipulation
#define BCD_TO_CHAR_HI(bcd) (char)(((bcd) >> 4) + '0')
#define BCD_TO_CHAR_LO(bcd) (char)(((bcd) & 0x0F) + '0')
#define CHARS_TO_BCD(h, l)  (uint8_t)((( (h) - '0') << 4) | ((l) - '0'))

// --- 1. STRING MACROS TO DS1307 BCD ---
void packDS1307(uint8_t *reg) {
    // Time: "hh:mm:ss" -> registers 0x02, 0x01, 0x00
    reg[0x00] = CHARS_TO_BCD(__TIME__[6], __TIME__[7]); // Seconds
    reg[0x01] = CHARS_TO_BCD(__TIME__[3], __TIME__[4]); // Minutes
    reg[0x02] = CHARS_TO_BCD(__TIME__[0], __TIME__[1]); // Hours

    // Date: "Mmm dd yyyy" -> registers 0x04, 0x05, 0x06
    char d_h = (__DATE__[4] == ' ' ? '0' : __DATE__[4]);
    reg[0x04] = CHARS_TO_BCD(d_h, __DATE__[5]);         // Day
    
    // Month Mapping
    const char *m[] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
    for (int i = 0; i < 12; i++) {
        if (strncmp(__DATE__, m[i], 3) == 0) {
            int val = i + 1;
            reg[0x05] = (uint8_t)((val / 10 << 4) | (val % 10)); // Month
            break;
        }
    }
    reg[0x06] = CHARS_TO_BCD(__DATE__[9], __DATE__[10]); // Year (e.g., 26)
}

// --- 2. DS1307 BCD TO STRINGS ---
void unpackDS1307(const uint8_t *reg, char *dateOut, char *timeOut) {
    const char *months[] = {"???","Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
    
    // Get Month Name
    int m_idx = ((reg[0x05] >> 4) * 10) + (reg[0x05] & 0x0F);
    const char *m_name = (m_idx >= 1 && m_idx <= 12) ? months[m_idx] : "???";

    // Format Date: "Mmm dd 20yy"
    char d_h = BCD_TO_CHAR_HI(reg[0x04]);
    if (d_h == '0') d_h = ' '; // Match __DATE__ space padding
    sprintf(dateOut, "%s %c%c 20%c%c", m_name, d_h, BCD_TO_CHAR_LO(reg[0x04]), 
            BCD_TO_CHAR_HI(reg[0x06]), BCD_TO_CHAR_LO(reg[0x06]));

    // Format Time: "hh:mm:ss"
    sprintf(timeOut, "%c%c:%c%c:%c%c", 
            BCD_TO_CHAR_HI(reg[0x02] & 0x3F), BCD_TO_CHAR_LO(reg[0x02]), // Mask 12/24h bit
            BCD_TO_CHAR_HI(reg[0x01]), BCD_TO_CHAR_LO(reg[0x01]), 
            BCD_TO_CHAR_HI(reg[0x00] & 0x7F), BCD_TO_CHAR_LO(reg[0x00])); // Mask CH bit
}

int main() {
    uint8_t rtc_regs[7]; // Simulating DS1307 memory
    char dStr[12], tStr[9];

    packDS1307(rtc_regs);
    unpackDS1307(rtc_regs, dStr, tStr);

    printf("Original: %s %s\n", __DATE__, __TIME__);
    printf("Restored: %s %s\n", dStr, tStr);
    return 0;
}

