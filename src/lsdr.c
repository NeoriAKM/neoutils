// ---------------------------------------- //
// lsdr: shows list of files from directory //
//                                          //
//        Author: NeoriAKM                  //
// ---------------------------------------- //

#include <string.h>
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

    if (argc > 1) for (int i=1; i<argc; i++) {
        if (argv[i][0] == '-') {
            if      (strcmp(argv[i], "-a")==0) flag.all = 1;
            else if (strcmp(argv[i], "-n")==0) flag.numeration = 1;
        } else {
            if (strcmp(dirname, ".")==0) dirname = argv[i];
            else printf("[WARN] type directory name only once\n");
        }
    }

    DIR* dir = opendir(dirname);
    if (dir == NULL) {
        printf("[ERROR] Couldn't open directory");
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