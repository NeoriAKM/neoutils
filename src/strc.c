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


int main(int argc, char* argv[]) {

    char* filename = "";
    int filename_typed = 0;
    int openval; // value, thats will return open(...)

    if (argc > 1) for (int i=1; i<argc; i++) {
        if (argv[i][0] == '-') {
            printf("Sorry, but flags not added :D Coming soon\n");
        } else {
            if (!filename_typed) {
                filename = argv[i];
                filename_typed = 1;
            }
            else fprintf(stderr, "[WARN] type filename once. '%s' skipped\n", argv[i]);
        }
    } else if (argc < 2) {printf("No file entered. closing program\n"); return 1;}

    openval = filename_typed ? open(filename, O_RDONLY) : STDIN_FILENO;

    if (openval == -1) {
        printf("[ERROR] ");
        perror("strc");
        return 1;
    }

    char buf[1024];
    ssize_t b_read;
    int lines = 1;

    while ((b_read = read(openval, buf, sizeof(buf))) > 0) {
        for (ssize_t i=0; i < b_read; i++) {
            if (buf[i] == '\n') lines++;
        }
    }

    printf("%s have a: %i lines", filename, lines);

    if (openval!=STDIN_FILENO) close(openval);
    return 0;
}