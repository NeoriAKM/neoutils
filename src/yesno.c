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

int read_char() {
    char ch;
    if (read(0, &ch, 1) == 1) {
        return ch;
    }
    return -1;
}

char* color1 = "\033[32m";
char* color2 = "\033[34m";
char* color_end = "\033[0m";

int main(int argc, char *argv[]) {

    int no = 0;

    char* question;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--version") == 0) {        // version
            prints("----------------------------------------------\n");
            prints("yesno v0.1 | by "); prints(color2); prints("Neori");
            prints(color_end); prints(" | Made for "); prints(color2);
            prints("ProgwiLinux\n"); prints(color_end);
            prints("----------------------------------------------\n");
            prints("Questing user.\n");
            prints("More: https://neoriakm.github.io/neoutils\n");
            prints("----------------------------------------------\n");
            return 0;
        } else if (strcmp(argv[i], "-n") == 0) {    // no
            no = 1;
        } else if (strcmp(argv[i], "--help") == 0) {    // help
            prints("                     ");
            prints(color2);
            prints("Usage of yesno\n");
            prints(color1);
            prints("--------------------------------------------------------\n");
            prints(color_end);
            prints("yesno <question>           questing user\n");
            prints("                    ");
            prints(color2);
            prints("Flags/arguments\n");
            prints(color1);
            prints("--------------------------------------------------------\n");
            prints(color_end);
            prints(" --version          prints info about yesno\n");
            prints(" --help             opening this text\n");
            return 0;
        } else {
            if (argv[i][0] != '-') {
                question = argv[i];
            }
        }
    }


    if (!question) {
        prints("Error: Question can't be empty, sorry");
        return -1;
    }

    prints(question);
    if (no == 1) prints("\n[y/N]");
    else prints("\n[Y/n]");
    int answer = read_char();
    if (answer == 'y' || answer == 'Y') {
        return 0;
    } else if (answer == 'n' || answer == 'N') {
        return 1;
    } else {
        return no ? 1 : 0;
    }

    return -1;
}