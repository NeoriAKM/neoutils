#include <unistd.h>
#define prints(s) write(1, s, strlen(s))

size_t strlen(const char *s) {
    const char *p = s;
    while (*p) p++;
    return p - s;
}

int strcmp(const char *s1, const char *s2) {
    while (*s1 && *s2 && *s1 == *s2) {s1++; s2++;}
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}


const char* color1 = "\033[32m";
const char* color2 = "\033[34m";
const char* color_end = "\033[0m";

int main(int argc, char *argv[]) {

    int e = 0;
    int n = 0;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--version") == 0) {        // version
            prints("----------------------------------------------\n");
            prints("echo v1.2.2 | by "); prints(color2); prints("Neori");
            prints(color_end); prints(" | Made for "); prints(color2);
            prints("ProgwiLinux\n"); prints(color_end);
            prints("----------------------------------------------\n");
            prints("Utilite for printing an information\n");
            prints("More: https://neoriakm.github.io/neoutils\n");
            prints("----------------------------------------------\n");
            return 0;
        } else if (strcmp(argv[i], "-e") == 0) {    // e
            e = 1;
        } else if (strcmp(argv[i], "-n") == 0) {    // n
            n = 1;
        } else if (strcmp(argv[i], "--help") == 0) {    // help
            prints("                     ");
            prints(color2);
            prints("Usage of echo\n");
            prints(color1);
            prints("--------------------------------------------------------\n");
            prints(color_end);
            prints("echo <text>         print your text\n\n");
            prints("                    ");
            prints(color2);
            prints("Flags/arguments\n");
            prints(color1);
            prints("--------------------------------------------------------\n");
            prints(color_end);
            // prints(" -e                 making '\\n' a working\n");
            // prints(" -n                 removing auto-'\\n' in the end of the output\n");
            prints(" --version          prints info about echo\n");
            prints(" --help             opening this text\n");
            return 0;
        } else {
            prints(argv[i]);
            prints(" ");
        }
    }
    if (n == 0) prints("\n");
}