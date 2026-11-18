// -------------------------- //
// dog: read files on your pc //
//                            //
// ?    Author: NeoriAKM    ? //
// -------------------------- //

#include <string.h>
#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
#include "../lib/pub.h"

void flush_out(char* buf, size_t* len) {
    if (*len > 0) {
        write(STDOUT_FILENO, buf, *len);
        *len = 0;
    }
}

struct flags {
    int numeration;
};

int main(int argc, char* argv[]) {
    struct flags flag;

    flag.numeration = 0;

    char* filename = "";
    int filename_typed = 0;
    int openval; // value, thats will return open(...)

    if (argc > 1) for (int i=1; i<argc; i++) {
        if (argv[i][0] == '-') {
            if (argv[i][1] == '-') {
                if      (strcmp(argv[i], "--nums")==0) flag.numeration = 1;
                else if (strcmp(argv[i], "--help")==0) {help_msg("dog"); return 0;}

                else fprintf(stderr, "[WARN] Unknown flag: %s\n", argv[i]);
            } else {
                for (int j = 1; argv[i][j] != '\0'; j++) {
                    if (argv[i][j] == 'n') flag.numeration = 1;
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
        perror("dog");
        return 1;
    }

    char buf[1024];
    char outbuf[4096];
    size_t outlen = 0;
    ssize_t b_read;
    int sindex = 1;
    int at_line_start = 1;

    while ((b_read = read(openval, buf, sizeof(buf))) > 0) {
        for (ssize_t i=0; i < b_read; i++) {

            if (flag.numeration && at_line_start) {
                if (sizeof(outbuf) - outlen < 32) {
                    flush_out(outbuf, &outlen);
                }
                outlen += (size_t)snprintf(outbuf + outlen, sizeof(outbuf) - outlen, "%d. ", sindex);
                at_line_start = 0;
            }

            if (outlen >= sizeof(outbuf) - 1) {
                flush_out(outbuf, &outlen);
            }
            outbuf[outlen++] = buf[i];

            if (buf[i] == '\n') {
                flush_out(outbuf, &outlen);
                sindex++;
                at_line_start = 1;
            }
        }
    }
    flush_out(outbuf, &outlen);
    if (openval!=STDIN_FILENO) close(openval);
    return 0;
}