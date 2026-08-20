#include <unistd.h>
#include <fcntl.h>

char* color1 = "\033[32m";
char* color2 = "\033[34m";
char* color_end = "\033[0m";

int strcmp(const char *s1, const char *s2) {
    while (*s1 && *s2 && *s1 == *s2) {s1++; s2++;}
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}

size_t strlen(const char *s) {
    const char *p = s;
    while (*p) p++;
    return p - s;
}

static void prints(const char* text) {write(1, text, strlen(text));}

int main(int argc, char* argv[]) {

    char* filename = "";

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--version") == 0) {        // version
            prints("----------------------------------------------\n");
            prints("touch v0.1 | by "); prints(color2); prints("Neori");
            prints(color_end); prints(" | Made for "); prints(color2);
            prints("ProgwiLinux\n"); prints(color_end);
            prints("----------------------------------------------\n");
            prints("making empty files\n");
            prints("More: https://neoriakm.github.io/neoutils\n");
            prints("----------------------------------------------\n");
            return 0;
        } else if (strcmp(argv[i], "--help") == 0) {    // help
            prints("                     ");
            prints(color2);
            prints("Usage of touch\n");
            prints(color1);
            prints("--------------------------------------------------------\n");
            prints(color_end);
            prints("touch <name>           Making a named file\n");
            prints("                    ");
            prints(color2);
            prints("Flags/arguments\n");
            prints(color1);
            prints("--------------------------------------------------------\n");
            prints(color_end);
            prints(" --version          prints info about touch\n");
            prints(" --help             opening this text\n");
            return 0;
        } else {
            if (argv[i][0] != '-') filename = argv[i];
        }
    }

    if (strcmp(filename, "")) {
        prints("touch: missing file operand\n");
        prints("Try 'touch --help' for more information.\n");
        return 1;
    }

    int fd = open(filename, O_WRONLY | O_CREAT | O_NOCTTY, 0644);

    if(fd < 0) {
        prints("touch: cannot touch '");
        prints(filename);
        prints("'\n");
        return 1;
    }
    close(fd); return 0;
}