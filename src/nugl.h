// NUGL == NeoUtils Global Lib

#ifndef NUGL_H
#define NUGL_H
#include <unistd.h>

static size_t len(const char *s) {
    const char *p = s;
    while (*p) p++;
    return p - s;
}

static int cmp(const char *s1, const char *s2) {
    while (*s1 && *s2 && *s1 == *s2) {s1++; s2++;}
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}

static void prints(const char* text) {write(1, text, len(text));}

static void printi(int n) {
    char buf[32];
    int i = 0;
    int negative = 0;
    
    // if (n < 0) {negative = 1; n = -n;}
    unsigned int u = n < 0 ? -(unsigned int)n : n;
    do {buf[i++] = '0' + u % 10;} while (u /= 10);

    if (negative) {buf[i++] = '-';}
    while (i--) {write(1, &buf[i], 1);}
}

static void println(const char* text)
{write(1, text, len(text)); write(1, "\n", 1);}


static int toint(const char *str) {
    int result = 0;
    int i = 0;
    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return result;
}

#endif