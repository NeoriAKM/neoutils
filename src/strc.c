 // ---------------------------------- //
// StrC: counter for strings in files //
//                                    //
// ?        Author: NeoriAKM        ? //
// ---------------------------------- //
// StrC = Strings Counter (inspired by wc)

#include <stdio.h>
#include <fcntl.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include "../lib/pub.h"

struct flags {
    int words;
    int lines;
    int chars;
};

int main(int argc, char* argv[]) {

    // flags
    struct flags flag;
    flag.lines = 1;
    flag.words = 0;
    flag.chars = 0;

    // other
    char* filename = "";
    int filename_typed = 0;
    int openval; // value, thats will return open(...)

    // ! ARG PARSING ¡ //

    if (argc > 1) for (int i=1; i<argc; i++) {
        if (argv[i][0] == '-') {
            // full
            if (argv[i][1] == '-') {
                if      (strcmp(argv[i], "--lines")==0)  flag.lines = 1;
                else if (strcmp(argv[i], "--words")==0) {flag.words = 1; flag.lines = 0;}
                else if (strcmp(argv[i], "--chars")==0) {flag.chars = 1; flag.lines = 0;}
                else if (strcmp(argv[i], "--help") ==0) {help_msg("strc"); return 0;}

                else fprintf(stderr, "[WARN] Unknown flag: %s\n", argv[i]);
            } else { // 1 ltr
                for (int j = 1; argv[i][j] != '\0'; j++) {
                    if      (argv[i][j] == 'l'); // NOP
                    else if (argv[i][j] == 'w') {flag.words = 1; flag.lines = 0;}
                    else if (argv[i][j] == 'c') {flag.chars = 1; flag.lines = 0;}
                    else if (argv[i][j] == 'h') {help_msg("strc"); return 0;}

                    else fprintf(stderr, "[WARN] Unknown flag: -%c\n", argv[i][j]);
                }
            }
        } else {
            if (!filename_typed) {
                filename = argv[i];
                filename_typed = 1;
            }
            else fprintf(stderr, "[WARN] type filename once. '%s' skipped\n", argv[i]);
        }
    }


    openval = filename_typed ? open(filename, O_RDONLY) : STDIN_FILENO;

    if (openval == -1) {
        printf("[ERROR] ");
        perror("strc");
        return 1;
    }



    char buf[1024];
    ssize_t b_read;
    int counted = 0;
    int mode = flag.lines ? 'l' : (flag.chars ? 'c' : 'w');
    char prev_char = '\0';

    while ((b_read = read(openval, buf, sizeof(buf))) > 0) {
        for (ssize_t i=0; i < b_read; i++) {
            switch (mode) {
                case 'c': counted++;                                              break;
                case 'w': if (buf[i] == ' ' && prev_char != ' ' && i>0) counted++; break;
                default : if (buf[i] == '\n') counted++;                          break;
            }
            prev_char = buf[i];
        }
    }

    if (prev_char != '\n' && flag.lines) counted++;

    printf(
        "%s have a: %i %s", filename, counted,
        (flag.lines) ? "lines" : (flag.chars) ? "characters" : "words"
    );

    if (openval!=STDIN_FILENO) close(openval);
    return 0;
}