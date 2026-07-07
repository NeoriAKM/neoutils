#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    DIR *dir;
    struct dirent *entry;
    char* path;
    
    char* color1 = "\033[32m";
    char* color2 = "\033[34m";
    char* fat = "\033[1m";

    char* color_end = "\033[0m";
    char* current_color;
    int color_switch = 0;

    // флаги
    int showall = 0;
    int fast = 0;

    path = ".";

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--version") == 0) {        // version
            printf("----------------------------------------------\n");
            printf("LSDR v1.0 | By %sNeori%s | Made for %sProgwiLinux%s\n",
                color2, color_end, color2, color_end);
            printf("----------------------------------------------\n");
            printf("Basic program to show list of the\n");
            printf("content from dir. Analog of 'ls'\n");
            printf("----------------------------------------------\n");
            return 0;
        } else if (strcmp(argv[i], "-a") == 0) {        // all
            showall = 1;
        } else if (strcmp(argv[i], "-f") == 0 || strcmp(argv[i], "--fast") == 0) {  // fast
            fast = 1;
        } else if (strcmp(argv[i], "--help") == 0) {    // help
            printf("                     %sUsage of lsdr%s        \n", color2, color_end);
            printf("%s--------------------------------------------------------%s\n",
                color1, color_end);
            printf("lsdr <path>         shows folders and files from that folder\n");
            printf("lsdr                shows content from user folder\n");
            printf("\n");
            printf("                    %sFlags/arguments%s\n", color2, color_end);
            printf("%s--------------------------------------------------------%s\n",
                color1, color_end);
            printf(" -a      all        shows all content, even hiden\n");
            printf(" --version          prints info about LSDR\n");
            printf(" -f     --fast      disables delay between items\n");
            // printf(" -l      long       shows size (files) and file count (dirs)\n");
            printf(" --help             opening this text\n");
            return 0;
        } else {
            path = argv[i];
        }
    }


    dir = opendir(path);

    if (dir == NULL) {
        perror("opendir");
        return 1;
    }

    int count = 0;
    while ((entry = readdir(dir)) != NULL) {

        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {continue;}
        if (showall == 0) {if (entry->d_name[0] == '.') {continue;}}
        
        struct stat file_stat;
        char full_path[512];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);
    
        int is_dir = 0;
        if (stat(full_path, &file_stat) == 0) {
            is_dir = S_ISDIR(file_stat.st_mode);
        }
        if (is_dir) {printf("%s", fat);}


        if (color_switch == 1) {
            printf("%s%s%s\n", color1, entry->d_name, color_end);
            color_switch = 0;
        } else if (color_switch == 0) {
            printf("%s%s%s\n", color2, entry->d_name, color_end);
            color_switch = 1;
        }

        
        count++;
        printf("%s", color_end);
	    if (!fast) usleep(50000);
    }
    closedir(dir);
    return 0;
}


// TODO:
// 1. -f            +
// 2. -l            -
// 3. cursive       +