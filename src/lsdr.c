#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>

size_t strlen(const char *s) {
    const char *p = s;
    while (*p) p++;
    return p - s;
}

int strcmp(const char *s1, const char *s2) {
    while (*s1 && *s2 && *s1 == *s2) {s1++; s2++;}
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}

static void prints(const char* text) {write(1, text, strlen(text));}
static void printi(int n) {
    char buf[12];
    int i = 0;
    int negative = 0;
    if (n < 0) {negative = 1; n = -n;}
    do {buf[i++] = '0' + n % 10;}
    while (n /= 10);
    if (negative) {buf[i++] = '-';}
    while (i--) {write(1, &buf[i], 1);}
}

DIR *dir;
struct dirent *entry;
char* path = ".";

char* color1 = "\033[32m";
char* color2 = "\033[34m";
char* fat = "\033[1m";

char* color_end = "\033[0m";
char* current_color;
int color_switch = 0;
int count = 1;

// флаги
int showall = 0;
int fast = 0;
int numerate = 0;


int main(int argc, char *argv[]) {

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--version") == 0) {        // version
            prints("----------------------------------------------\n");
            prints("LSDR v1.2.2 | by "); prints(color2); prints("Neori");
            prints(color_end); prints(" | Made for "); prints(color2);
            prints("ProgwiLinux\n"); prints(color_end);
            prints("----------------------------------------------\n");
            prints("Basic program to show list of the\n");
            prints("content from dir. Analog of 'ls'\n");
            prints("More: https://neoriakm.github.io/neoutils\n");
            prints("----------------------------------------------\n");
            return 0;
        } else if (strcmp(argv[i], "-a") == 0) {        // all
            showall = 1;
        } else if (strcmp(argv[i], "-f") == 0 || strcmp(argv[i], "--fast") == 0) {  // fast
            fast = 1;
        } else if (strcmp(argv[i], "-n") == 0 || strcmp(argv[i], "--numerate") == 0) {  // numerate
            numerate = 1;
        } else if (strcmp(argv[i], "--help") == 0) {    // help
            prints("                     ");
            prints(color2);
            prints("Usage of lsdr\n\n");
            prints(color1);
            prints("--------------------------------------------------------\n");
            prints(color_end);
            prints("lsdr <path>         shows folders and files from that folder\n");
            prints("lsdr                shows content from user folder\n\n");
            prints("                    ");
            prints(color2);
            prints("Flags/arguments\n");
            prints(color1);
            prints("--------------------------------------------------------\n");
            prints(color_end);
            prints(" -a      all        shows all content, even hiden\n");
            prints(" --version          prints info about LSDR\n");
            prints(" -f     --fast      disables delay between items\n");
            // prints(" -l      long       shows size (files) and file count (dirs)\n");
            prints(" -n    --numerate   adds numerarion\n");
            prints(" --help             opening this text\n");
            return 0;
        } else {
            path = argv[i];
        }
    }


    dir = opendir(path);

    if (dir == NULL) {
        prints("No such directory, sorry");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL) {

        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {continue;}
        if (showall == 0) {if (entry->d_name[0] == '.') {continue;}}
        
        struct stat file_stat;
        char full_path[512];

        char *p = full_path;
        char *src;

        src = path;
        while (*src) *p++ = *src++;
        *p++ = '/';

        src = entry->d_name;
        while (*src) *p++ = *src++;
        *p = '\0';
    
        int is_dir = 0;
        if (stat(full_path, &file_stat) == 0) {
            is_dir = S_ISDIR(file_stat.st_mode);
        }
        if (is_dir) {prints(fat);}


        if (color_switch == 1) {
            if (numerate == 1) {
                prints(color1);
                printi(count);
                prints(". ");
                prints(color2);
                prints(entry->d_name);
                prints(color_end);
            } else if (numerate == 0) {
                prints(color2);
                prints(entry->d_name);
                prints(color_end);
            }
            color_switch = 0;
        } else if (color_switch == 0) {
            if (numerate == 1) {
                prints(color2);
                printi(count);
                prints(". ");
                prints(color1);
                prints(entry->d_name);
                prints(color_end);
            } else if (numerate == 0) {
                prints(color1);
                prints(entry->d_name);
                prints(color_end);
            }
            color_switch = 1;
        }

        
        count++;
        prints(color_end);
	prints("\n");
	    if (!fast) usleep(50000);
    }
    closedir(dir);
    return 0;
}