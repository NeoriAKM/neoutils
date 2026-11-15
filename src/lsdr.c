// ---------------------------------------- //
// lsdr: shows list of files from directory //
//                                          //
//            Author: NeoriAKM              //
// ---------------------------------------- //

// #include <string.h>
#include <stdio.h>
#include <dirent.h>

struct flags {
    int all;
    int numeration;
};

int main(int argc, char* argv[]) {
    struct flags flag;

    flag.all = 0;
    flag.numeration = 0;

    char* dirname = ".";
    int dirname_typed = 0;

    if (argc > 1) for (int i=1; i<argc; i++) {
        if (argv[i][0] == '-') {
            for (int j = 1; argv[i][j] != '\0'; j++) {
                if      (argv[i][j] == 'a') flag.all = 1;
                else if (argv[i][j] == 'n') flag.numeration = 1;
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
    if (dir == NULL) {
        fprintf(stderr, "[ERROR] Couldn't open directory\n");
        return 1;
    }
    struct dirent* entry;
    int findex = 1;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.' && flag.all == 0) continue;

        if (flag.numeration) printf("%i. ", findex);

        printf("%s\n", entry->d_name);
        findex++;
    }

    closedir(dir);
    return 0;
}