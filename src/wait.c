#include "nugl.h"

char* color1 = "\033[32m";
char* color2 = "\033[34m";
char* color_end = "\033[0m";

int main(int argc, char *argv[]) {

    int wait = 0;

    int micro = 0;
    int seconds = 0;
    int minutes = 0;
    // int nano = 0;

    for (int i = 1; i < argc; i++) {
        if (cmp(argv[i], "--version") == 0) {        // version
            prints("----------------------------------------------\n");
            prints("time v0.2 | by "); prints(color2); prints("Neori");
            prints(color_end); prints(" | Made for "); prints(color2);
            prints("ProgwiLinux\n"); prints(color_end);
            prints("----------------------------------------------\n");
            prints("Utilite for scripts. Waiting any time\n");
            prints("More: https://neoriakm.github.io/neoutils\n");
            prints("----------------------------------------------\n");
            return 0;
        } else if (cmp(argv[i], "-s") == 0) {    // seconds
            seconds = 1;
        } else if (cmp(argv[i], "-m") == 0) {    // minutes
            minutes = 1;
        } else if (cmp(argv[i], "-u") == 0) {    // micro
            micro = 1;
        // } else if (cmp(argv[i], "-n") == 0) {    // nano
        //     nano = 1;
        } else if (cmp(argv[i], "--help") == 0) {    // help
            prints("                     ");
            prints(color2);
            prints("Usage of time\n");
            prints(color1);
            prints("--------------------------------------------------------\n");
            prints(color_end);
            prints("time <ms>           waiting a time, typed in second argument\n");
            prints("                    ");
            prints(color2);
            prints("Flags/arguments\n");
            prints(color1);
            prints("--------------------------------------------------------\n");
            prints(color_end);
            prints("  -s                waiting in seconds (without - milliseconds)\n");
            prints("  -m                waiting in minutes\n");
            prints("  -u                waiting in microseconds\n");
            // prints("  -n                waiting in nanoseconds\n");
            prints(" --version          prints info about time\n");
            prints(" --help             opening this text\n");
            return 0;
        } else {
            wait = toint(argv[i]);
        }
    }

    if (seconds == 1)      sleep(wait);
    else if (minutes == 1) sleep(wait * 60);
    else if (micro == 1)   usleep(wait);
 // else if (nano == 1)    nanosleep(wait);
    else                   usleep(wait * 1000);

    return 0;
}