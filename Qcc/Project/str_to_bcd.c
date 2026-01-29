#include <stdio.h>
#include <stdint.h>
#include <string.h>

// Struct to store build info in Packed BCD
typedef struct {
    uint8_t month;  // 0x01 - 0x12
    uint8_t day;    // 0x01 - 0x31
    uint8_t year_h; // Century (e.g., 0x20)
    uint8_t year_l; // Year (e.g., 0x26)
    uint8_t hour;   // 0x00 - 0x23
    uint8_t min;    // 0x00 - 0x59
    uint8_t sec;    // 0x00 - 0x59
} BuildTimestamp;

// Macros for quick character-to-BCD conversion
#define CHARS_TO_BCD(h, l) (uint8_t)(((h - '0') << 4) | (l - '0'))

uint8_t getMonthBCD(const char *date) {
    const char *months[] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
    for (int i = 0; i < 12; i++) {
        if (strncmp(date, months[i], 3) == 0) {
            int m = i + 1;
            return (uint8_t)((m / 10 << 4) | (m % 10));
        }
    }
    return 0;
}

void getBuildTimestamp(BuildTimestamp *ts) {
    // 1. Parse __DATE__ ("Mmm dd yyyy")
    ts->month  = getMonthBCD(__DATE__);
    // Handle space padding for days < 10 (e.g., "Jan  5")
    char d_high = (__DATE__[4] == ' ' ? '0' : __DATE__[4]);
    ts->day    = CHARS_TO_BCD(d_high, __DATE__[5]);
    ts->year_h = CHARS_TO_BCD(__DATE__[7], __DATE__[8]);
    ts->year_l = CHARS_TO_BCD(__DATE__[9], __DATE__[10]);

    // 2. Parse __TIME__ ("hh:mm:ss")
    ts->hour = CHARS_TO_BCD(__TIME__[0], __TIME__[1]);
    ts->min  = CHARS_TO_BCD(__TIME__[3], __TIME__[4]);
    ts->sec  = CHARS_TO_BCD(__TIME__[6], __TIME__[7]);
}

int main() {
    BuildTimestamp ts;
    getBuildTimestamp(&ts);

    printf("Build: %s %s\n", __DATE__, __TIME__);
    printf("BCD Timestamp: %02X/%02X/%02X%02X at %02X:%02X:%02X\n",
            ts.month, ts.day, ts.year_h, ts.year_l, ts.hour, ts.min, ts.sec);
    return 0;
}

