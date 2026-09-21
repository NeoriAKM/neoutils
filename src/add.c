#include <unistd.h>
#include <stdio.h>

const char* color1 = "\033[32m";
const char* color2 = "\033[34m";
const char* color_end = "\033[0m";

int cmp(const char *s1, const char *s2) {
    while (*s1 && *s2 && *s1 == *s2) {s1++; s2++;}
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}

size_t len(const char *s) {
    const char *p = s;
    while (*p) p++;
    return p - s;
}

static void prints(const char* text) {write(1, text, len(text));}

int main(int argc, char* argv[]) {

    char* filename = NULL;
    int fc_flag = 0;

    for (int i = 1; i < argc; i++) {
        if (cmp(argv[i], "--version") == 0) {        // version
            prints("----------------------------------------------\n");
            prints("add v0.1 | by "); prints(color2); prints("Neori");
            prints(color_end); prints(" | Made for "); prints(color2);
            prints("ProgwiLinux\n"); prints(color_end);
            prints("----------------------------------------------\n");
            prints("making empty files. Analog of GNU touch\n");
            prints("More: https://neoriakm.github.io/neoutils\n");
            prints("----------------------------------------------\n");
            return 0;
        } else if (cmp(argv[i], "--help") == 0) {    // help
            prints("                     ");
            prints(color2);
            prints("Usage of add\n");
            prints(color1);
            prints("--------------------------------------------------------\n");
            prints(color_end);
            prints("add <name>           Making a named file\n");
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
            fc_flag++;
            if (fc_flag > 1) {
                prints("Sorry, but you can make only 1 file per command.\n");
                return 1;
            }
        }
    }


    if (!filename) {
        prints("add: missing file operand\n");
        prints("Try 'add --help' for more information.\n");
        return 1;
    }

    FILE* newfile = fopen(filename, "w");
    if(!newfile) {
        prints("touch: cannot touch '");
        prints(filename);
        prints("'\n");
        prints("Cause: ");
        if (filename[-1] == '_' || filename[1] == '_') {
            prints("File cannot having a '_' on start or end of name\n");
        } else {
            prints("Undefined error\n");
        }
        return 1;
    }
    fclose(newfile);
    return 0;
}