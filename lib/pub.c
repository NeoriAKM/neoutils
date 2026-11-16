#include <stdio.h>
#include <string.h>

int help_msg(char* util_name) {
    if (strcmp(util_name, "lsdr")==0) {
        printf("--------------------------------------------------------\n");
        printf(" -h  --help     showing this reference\n");
        printf(" -v  --version  showing license text and version of util\n");
        printf(" -a  --all      prints ALL files without excludes\n");
        printf(" -n  --nums     Writing index before a filename");
        printf("--------------------------------------------------------\n");
    }
    return 0;
}