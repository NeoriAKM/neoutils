// ---------------------------------------- //
// lsdr: shows list of files from directory //
//                                          //
// ?          Author: NeoriAKM            ? //
// ---------------------------------------- //

#include <string.h>
#include <stdio.h>
#include <dirent.h>
#include "../lib/pub.h"
#include <sys/stat.h>

struct flags {
    int all;
    int numeration;
    int colors;
};

int main(int argc, char* argv[]) {
    struct flags flag;

    flag.all = 0;
    flag.numeration = 0;
    flag.colors = 1;

    char* dirname = ".";
    int dirname_typed = 0;

    if (argc > 1) for (int i=1; i<argc; i++) {
        if (argv[i][0] == '-') {

            // full flag name
            if (argv[i][1] == '-') {
                if      (strcmp(argv[i], "--all" ) ==0) flag.all = 1;
                else if (strcmp(argv[i], "--nums") ==0) flag.numeration = 1;
                else if (strcmp(argv[i], "--no-color")==0) flag.colors = 0;
                else if (strcmp(argv[i], "--help") ==0) {help_msg("lsdr"); return 0;}

                else fprintf(stderr, "[WARN] Unknown flag: %s\n", argv[i]);

            // simple 1-letter flag
            } else {
                for (int j = 1; argv[i][j] != '\0'; j++) {
                    if      (argv[i][j] == 'a') flag.all = 1;
                    else if (argv[i][j] == 'n') flag.numeration = 1;

                    else fprintf(stderr, "[WARN] Unknown flag: -%c\n", argv[i][j]);
                }
            }
        } else {
            if (!dirname_typed) {
                dirname = argv[i];
                dirname_typed = 1;
            }
            else fprintf(stderr, "[WARN] type directory name only once\n");
        }
    }

    DIR* dir = opendir(dirname);
    if (dir == NULL) {fprintf(stderr, "[ERROR] Couldn't open directory\n"); return 1;}

    struct dirent* entry;
    int findex = 1;
    int color_loop = 0;

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.' && flag.all == 0) continue;
        if (entry->d_type == DT_DIR) printf("%s", colfat);

        if (flag.numeration) {
            if (flag.colors) {
                if (color_loop==0) printf("%s", col1);
                else printf("%s", col2);
            }
            printf("%5d. ", findex);
        }

        if (flag.colors) {
            if (color_loop==0) printf("%s", col2);
            else printf("%s", col1);
        }
        printf("%s\n", entry->d_name);

        findex++;
        if (flag.colors) {
            if      (color_loop==0) color_loop = 1;
            else if (color_loop==1) color_loop = 0;
        }
        printf("%s", col0);
    }


    closedir(dir);
    printf("%s", col0);
    return 0;
}