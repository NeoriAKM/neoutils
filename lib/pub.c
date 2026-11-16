#include <stdio.h>
#include <string.h>

int help_msg(const char* util_name) {
    if (strcmp(util_name, "lsdr")==0) {
        printf(""
            "--------------------------------------------------------\n"
            " -h  --help     showing this reference\n"
            " -a  --all      prints ALL files without excludes\n"
            " -n  --nums     Writing index before a filename\n"
            "--------------------------------------------------------\n"
        );
    }
    return 0;
}