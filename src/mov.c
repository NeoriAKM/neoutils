#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

size_t len(const char *s) {
    const char *p = s;
    while (*p) p++;
    return p - s;
}

int cmp(const char *s1, const char *s2) {
    while (*s1 && *s2 && *s1 == *s2) {s1++; s2++;}
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}

static void prints(const char* text) {write(1, text, len(text));}


char* color1 = "\033[32m";
char* color2 = "\033[34m";
char* color_end = "\033[0m";

char* green = "\033[32m";
char* red = "\033[31m";

int main(int argc, char* argv[]) {
    
    char* old_path = NULL;
    char* new_path = NULL;

    // flags
    int logs = 0;
    
    for (int i = 1; i < argc; i++) {
        if (cmp(argv[i], "--version") == 0) {        // version
            prints("----------------------------------------------\n");
            prints("mov 0.1 | by "); prints(color2); prints("Neori");
            prints(color_end); prints(" | Made for "); prints(color2);
            prints("ProgwiLinux\n"); prints(color_end);
            prints("----------------------------------------------\n");
            prints("Moving files from dir to dir.\n");
            prints("Analog of 'mv'\n");
            prints("More: https://neoriakm.github.io/neoutils\n");
            prints("----------------------------------------------\n");
            return 0;
        } else if (cmp(argv[i], "-l") == 0) {    // logs
            logs = 1;
        } else if (cmp(argv[i], "--help") == 0) {    // help
            prints("                     ");
            prints(color2);
            prints("Usage of mov\n");
            prints(color1);
            prints("--------------------------------------------------------\n");
            prints(color_end);
            prints("mov <path> <new path>   moving, and can rename file\n");
            prints("mov                     calling an error :D\n\n");
            prints("                    ");
            prints(color2);
            prints("Flags/arguments\n");
            prints(color1);
            prints("--------------------------------------------------------\n");
            prints(color_end);
            prints(" --version          prints info about mov\n");
            prints(" --help             opening this document\n");
            prints("  -l                printing logs about succefully moving\n");
            return 0;
        } else {

            if (old_path == NULL) {
                old_path = argv[i];
            } else if (new_path == NULL) {
                new_path = argv[i];
            }
        }
    }


    if (old_path == NULL || new_path == NULL) {
        prints(red);
        prints("mov need a 2 arguments, you did an mistake somewhere\n");
        prints("type 'mov --help' to reference\n");
        return 1;
    }

    struct stat st;
    if (stat(new_path, &st) == 0 && S_ISDIR(st.st_mode)) {
        
    }


    if (rename(old_path, new_path) == 0) {
        if (logs == 1) {
            prints(green);
            prints("Succefully moved!\n");
            prints("Old path - "); prints(old_path);
            prints("\n"); prints("New path - ");
            prints(new_path); prints("\n");
        }
        return 0;
    } else {
        prints(red);      prints("unknown error, cannot move ");
        prints(old_path); prints(" to ");
        prints(new_path); prints("'\n");
        return 1;
    }
}