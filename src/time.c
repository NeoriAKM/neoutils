#include <unistd.h>

size_t strlen(const char *s) {
    const char *p = s;
    while (*p) p++;
    return p - s;
}

int strcmp(const char *s1, const char *s2) {
    while (*s1 && *s2 && *s1 == *s2) {s1++; s2++;}
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}

int toint(const char *str) {
    int result = 0;
    int i = 0;
    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return result;
}

static void prints(const char* text) {write(1, text, strlen(text));}
static void printi(int n) {
    char buf[12];
    int i = 0;
    int negative = 0;
    if (n < 0) {negative = 1; n = -n;}
    do {buf[i++] = '0' + n % 10;}
    while (n /= 10);
    if (negative) {buf[i++] = '-';}
    while (i--) {write(1, &buf[i], 1);}
}

char* color1 = "\033[32m";
char* color2 = "\033[34m";
char* color_end = "\033[0m";

int main(int argc, char *argv[]) {

    int wait = 0;

    int micro = 0;
    int seconds = 0;
    int minutes = 0;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--version") == 0) {        // version
            prints("----------------------------------------------\n");
            prints("time v0.1 | by "); prints(color2); prints("Neori");
            prints(color_end); prints(" | Made for "); prints(color2);
            prints("ProgwiLinux\n"); prints(color_end);
            prints("----------------------------------------------\n");
            prints("Utilite for scripts. Waiting any time\n");
            prints("More: https://neoriakm.github.io/neoutils\n");
            prints("----------------------------------------------\n");
            return 0;
        } else if (strcmp(argv[i], "-s") == 0) {    // seconds
            seconds = 1;
        } else if (strcmp(argv[i], "-s") == 0) {    // minutes
            minutes = 1;
        } else if (strcmp(argv[i], "-s") == 0) {    // micro
            micro = 1;
        } else if (strcmp(argv[i], "--help") == 0) {    // help
            prints("                     ");
            prints(color2);
            prints("Usage of time\n");
            prints(color1);
            prints("--------------------------------------------------------\n");
            prints(color_end);
            prints("time <ms>           waiting a time, typed in secong argument\n");
            prints("                    ");
            prints(color2);
            prints("Flags/arguments\n");
            prints(color1);
            prints("--------------------------------------------------------\n");
            prints(color_end);
            prints("  -s                waiting in seconds (without - milliseconds)\n");
            prints("  -m                waiting in minutes\n");
            prints(" --version          prints info about time\n");
            prints(" --help             opening this text\n");
            return 0;
        } else {
            wait = toint(argv[i]);
        }
    }

    if (seconds == 1)      sleep(wait);
    else if (minutes == 1) sleep(wait * 60);
    else if (micro == 1)   usleep(wait);
    else                   usleep(wait * 1000);

    return 0;
}