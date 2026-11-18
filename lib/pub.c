#include <stdio.h>
#include <string.h>

int help_msg(const char* util_name) {
    if (strcmp(util_name, "lsdr")==0) {
        printf(""
            "--------------------------------------------------\n"
            " -h  --help     showing this reference\n"
            " -a  --all      prints ALL files without excludes\n"
            " -n  --nums     Writing index before a filename\n"
            "  --no-color    disabling green and cyan zebra\n"
            "--------------------------------------------------\n"
        );
    } else if (strcmp(util_name, "dog")==0) {
        printf(""
            "---------------------------------------\n"
            " -h  --help     showing this reference\n"
            " -n  --nums     Numerating numbers\n"
            "---------------------------------------\n"
        );
    }
    return 0;
}
const char* col0   = "\033[31;0m";
const char* col1   = "\033[31;36m";
const char* col2   = "\033[31;32m";
const char* colfat = "\033[1m";