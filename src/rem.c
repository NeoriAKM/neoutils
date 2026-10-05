#include <errno.h> // errno
#include <sys/stat.h> // stat
#include "nugl.h" // prints, cmp, len
#include <string.h> // strerror


const char* color1 = "\033[32m";
const char* color2 = "\033[34m";
const char* color_end = "\033[0m";

const char* green = "\033[32m";
const char* red = "\033[31m";

int main(int argc, char* argv[]) {
    
    struct stat st;
    char* to_remove = NULL;

    // flags
    int logs = 0;
    
    for (int i = 1; i < argc; i++) {
        if (cmp(argv[i], "--version") == 0) {        // version
            prints("----------------------------------------------\n");
            prints("rem 0.1 | by "); prints(color2); prints("Neori");
            prints(color_end); prints(" | Made for "); prints(color2);
            prints("ProgwiLinux\n"); prints(color_end);
            prints("----------------------------------------------\n");
            prints("Removing files. | Analog for 'rm\n");
            prints("More: https://neoriakm.github.io/neoutils\n");
            prints("----------------------------------------------\n");
            return 0;
        } else if (cmp(argv[i], "-l") == 0) {    // logs
            logs = 1;
        } else if (cmp(argv[i], "--help") == 0) {    // help
            prints(color2);
            prints("                    Usage of rem\n");
            prints(color1);
            prints("--------------------------------------------------------\n");
            prints(color_end);
            prints("rem <path>      deleting file\n");
            prints(color2);
            prints("                    Flags/arguments\n");
            prints(color1);
            prints("--------------------------------------------------------\n");
            prints(color_end);
            prints(" --version      prints info about rem\n");
            prints(" --help         opening this reference\n");
            prints("  -l            printing logs about succefully deleting\n");
            return 0;
        } else {

            if (to_remove == NULL) {
                to_remove = argv[i];
            } else {
                prints("Please, write filename only once\n");
                return 1;
            }
        }
    }

    if (to_remove == NULL) {
        prints("Please, type filename\n");
        return 1;
    }
    
    if (stat(to_remove, &st) != 0) {
        prints(red);       prints("File '");
        prints(to_remove); prints("' not found\n");
        prints(color_end);
        return 1;
    }

    if (S_ISDIR(st.st_mode)) {
        prints("You cannot delete a dir\n"); return 1;
    }

    if (unlink(to_remove) != 0) {
        prints(red); prints("Error: "); prints(strerror(errno)); prints("\n");
        prints(color_end);
        return 1;
    } else {
        if (logs == 1) {
            prints(green); prints("File "); prints(to_remove);
            prints(" Successfully removed!\n");    prints(color_end);
        }
        return 0;
    }
}