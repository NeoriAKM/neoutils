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
// #include <sys/stat.h>

struct flags {
    int all;
    int numeration;
    int colors;
    int large;
};

struct count {
    int dirs;
    int files;
    int undefined;
};

void print_size(struct stat *st, const char *color, const char *col_reset) {
    if (S_ISDIR(st->st_mode)) {
        printf("(      DIR) ");
        return;
    }

    long long size = st->st_size;

    if (size < 1024) {
        printf("(%5lld   %sB%s) ", size, color, col_reset);
    } else if (size < 1024 * 1024) {
        printf("(%5lld %sKiB%s) ", (size + 1023) / 1024, color, col_reset);
    } else if (size < 1024LL * 1024 * 1024) {
        printf("(%5lld %sMiB%s) ", (size + 1048575) / 1048576, color, col_reset);
    } else {
        printf("(%5lld %sGiB%s) ", (size + 1073741823) / 1073741824, color, col_reset);
    }
}

int main(int argc, char* argv[]) {
    struct flags flag;
    struct count counter;

    flag.all = 0;
    flag.numeration = 0;
    flag.colors = 1;
    flag.large = 0;

    counter.dirs      = 0;
    counter.files     = 0;
    counter.undefined = 0;

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
                else if (strcmp(argv[i], "--large")==0) flag.large = 1;

                else fprintf(stderr, "[WARN] Unknown flag: %s\n", argv[i]);

            // simple 1-letter flag
            } else {
                for (int j = 1; argv[i][j] != '\0'; j++) {
                    if      (argv[i][j] == 'a') flag.all = 1;
                    else if (argv[i][j] == 'n') flag.numeration = 1;
                    else if (argv[i][j] == 'l') flag.large = 1;

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
    struct stat file_stat;

    int findex = 1;
    int color_loop = 0;
    char* str_ender = "";

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.' && flag.all == 0) continue;

        char full_path[4096];
        snprintf(full_path, sizeof(full_path), "%s/%s", dirname, entry->d_name);

        if (entry->d_type == DT_DIR) {
            printf("%s", colfat);
            counter.dirs++;
        }
        else if (entry->d_type == DT_UNKNOWN) {str_ender = "(?)"; counter.undefined++;}
        else if (entry->d_type == DT_REG) counter.files++;

        if (flag.numeration) {
            if (flag.colors) printf("%s", (color_loop == 0) ? col1 : col2);
            printf("%5d. %s", findex, col0);
        }

        if (flag.large) {
            if (lstat(full_path, &file_stat) == 0) {
                const char *sz_col =(entry->d_type == DT_DIR) ? clr_siz_dir              :
                                    (file_stat.st_size < 1024*1024) ? clr_siz_low        :
                                    (file_stat.st_size < 1024LL*1024*1024) ? clr_siz_med : clr_siz_big;
                print_size(&file_stat, sz_col, col0);
            } else {
                printf("(    ??? KiB) ");
            }
        }

        if (flag.colors) printf("%s", (color_loop == 0) ? col2 : col1);
        if (entry->d_type == DT_DIR) printf("%s", colfat);
        printf("%s %s\n", entry->d_name, str_ender);

        findex++;
        if (flag.colors) {
            if      (color_loop==0) color_loop = 1;
            else if (color_loop==1) color_loop = 0;
        }
        printf("%s", col0);
        str_ender = "";
    }
    printf("%s\n", col0);

    if (flag.large == 1) {
        printf("%d dirs, %d files and %d undefineds\n", counter.dirs, counter.files, counter.undefined);
        printf("  in directory '%s'\n", dirname);
    }

    closedir(dir);
    return 0;
}