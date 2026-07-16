#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    char cwd[PATH_MAX];
    
    char* color1 = "\033[32m";
    char* color2 = "\033[34m";
    char* endc = "\033[0m";

    // флаги
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--version") == 0) {        // version
            printf("----------------------------------------------\n");
            printf("WhereamI v0.1.1 | By %sNeori%s | Made for %sProgwiLinux%s\n",
                color2, endc, color2, endc);
            printf("----------------------------------------------\n");
            printf("Program for getting a user directory\n");
            printf("Analog of 'pwd'\n");
            printf("----------------------------------------------\n");
            return 0;
        } else if (strcmp(argv[i], "--help") == 0 || strcmp(argv[i], "-h") == 0) { // help
            printf("                     %sUsage of whereami%s\n", color2, endc);
            printf("%s--------------------------------------------------------%s\n",
                color1, endc);
            printf("whereami          shows directory, where sitting a user\n");
            printf("\n");
            printf("                  %sFlags/arguments%s\n", color2, endc);
            printf("%s--------------------------------------------------------%s\n",
                color1, endc);
            printf(" --version        prints info about WAI\n");
            printf(" --help           opening this text\n");
            return 0;
        } else {
            fprintf(stderr, "Unknown flag: %s. Use --help or -h\n", argv[i]);
            return 1;
        }
    }
    if (getcwd(cwd, sizeof(cwd)) != NULL) {printf("%s\n", cwd);}
    else {perror("getcwd() error"); return 1;}
    return 0;
}
