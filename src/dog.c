#include <stdio.h>

size_t strlen(const char *s) {
    const char *p = s;
    while (*p) p++;
    return p - s;
}

int strcmp(const char *s1, const char *s2) {
    while (*s1 && *s2 && *s1 == *s2) {s1++; s2++;}
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}

int main(int argc, char *argv[]) {
    char *filename = NULL;
    FILE *file = NULL;
    char *color1 = "\033[32m";
    char *color2 = "\033[34m";
    char *endc = "\033[0m";

    int showall = 0;
    int nums = 0;
    int empty = 0;


    if (argc < 2) {
        printf("usage: dog <file>\n");
        return 1;
    } else {
        for (int i = 1; i < argc; i++) {
            if (strcmp(argv[i], "--version") == 0) {            // version
                printf("----------------------------------------------\n");
                printf("dog v0.2 | By %sNeori%s | Made for %sProgwiLinux%s\n",
                    color2, endc, color2, endc);
                printf("----------------------------------------------\n");
                printf("Program for reading a files.\n");
                printf("Analog of 'cat' from UNIX\n");
                printf("----------------------------------------------\n");
                return 0;
            } else if (strcmp(argv[i], "-a") == 0) {            // all
                showall = 1;
            } else if (strcmp(argv[i], "-n") == 0) {            // nums
                nums = 1;
            } else if (strcmp(argv[i], "-e") == 0) {            // empty
                empty = 1;
            } else if (strcmp(argv[i], "--help") == 0) {        // help
                printf("                     %sUsage of dog%s        \n", color2, endc);
                printf("%s--------------------------------------------------------%s\n",
                    color1, endc);
                printf("dog <path>         shows folders and files from that folder\n");
                printf("\n");
                printf("                    %sFlags/arguments%s\n", color2, endc);
                printf("%s--------------------------------------------------------%s\n",
                    color1, endc);
                printf(" -a      all        removing barier to files 500+ stringlines\n");
                printf(" --version          prints info about dog\n");
                printf(" --help             opening this reference\n");
                printf(" -n      nums       removing numbers for strings\n");
                printf(" -e    empty        removing empty strings");
                return 0;
            } else if (argv[i][0] != '-') {
                filename = argv[i];
            } else {
                printf("Unknown flag. --help for reference");
                return 1;
            }
        }
    }

    if (filename == NULL) {printf("No file specified. usage: dog <file>\n"); return 1;}

    file = fopen(filename, "r");
    if (file == NULL) {
        perror("fopen");
        return 1;
    }


    int line_num = 1;
    char line[512];
    while (fgets(line, sizeof(line), file) != NULL) {

        if (empty == 1 && strcmp(line, "\n") == 0) {line_num++; continue;}

        if (nums == 1) {printf("%s", line);}
        else {printf("%i. %s", line_num, line);}

        line_num++;

        if (line_num > 500 && showall == 0) {
            printf("\n...\n");
            fclose(file);
            return 0;
        }

    }
    fclose(file);
    return 0;
}