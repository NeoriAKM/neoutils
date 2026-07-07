#include <stdio.h>
#include <string.h>
#include <sys/statvfs.h>

int get_cpu() {
    FILE* f = fopen("/proc/cpuinfo", "r");
    if (!f) {
        perror("fopen");
        return 1;
    }

    char line[256];
    while (fgets(line, sizeof(line), f)) {
        if (strncmp(line, "model name", 10) == 0) {
            char* name = strchr(line, ':') + 2;
            name[strcspn(name, "\n")] = '\0';
            break;
        }
    }
    fclose(f);
    return name;
}

int get_disk_usage(const char* path, char* mode) {
    struct statvfs stats;
    if (statvfs(path, &stats) != 0) {
        perror("statvfs");
        return 1;
    }

    unsigned long long total = stats.f_blocks * stats.f_frsize;
    unsigned long long free = stats.f_bfree * stats.f_frsize;
    unsigned long long used = total - free;
    
    if (strcmp(mode, "total") == 0) {return total / 1024 / 1024 / 1024;}
    if (strcmp(mode, "used") == 0) {return used / 1024 / 1024 / 1024;}
    if (strcmp(mode, "used") == 0) {return used / 1024 / 1024 / 1024;}
}

int get_uptime() {
    FILE* f = fopen("/proc/uptime", "r");
    if (!f) {perror("fopen"); return 1;}

    double uptime_seconds;
    fscanf(f, "%lf", &uptime_seconds);
    fclose(f);

    int days = uptime_seconds / 86400;
    int hours = (uptime_seconds - days * 86400) / 3600;
    int minutes = (uptime_seconds - days * 86400 - hours * 3600) / 60;
    int seconds = (int)uptime_seconds % 60;

    return "%d days, %02d:%02d:%02d\n", days, hours, minutes, seconds;
}


int get_kver() {
    FILE* f = fopen("/proc/version", "r");
    if (!f) {perror("fopen");return 1;}

    char line[256];
    fgets(line, sizeof(line), f);
    fclose(f);

    char* version = strchr(line, ' ');
    if (version) {
        version++;
        char* end = strchr(version, ' ');
        if (end) *end = '\0';
        return version;
    }
}

int main(int argc, char *argv[]) {
    char* ram    = get_ram()
    char* cpu    = get_cpu()
    char* uptime = get_uptime()
    char* kver   = get_kver()

    if (!cpu || !ram || !uptime || !kver) {perror("fopen"); return 1;}



                   ........                   
            ...####@@@@@@@@####...            
           .@@@@@@@@@@@@@@@@@@@@@@.           
         ..@@@@@@@@@@@@@@@@@@@@@@@@..         
       .@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@.       
       .@@@@@}......@@@@@@......[@@@@@.       
     ..@@@@@...@@@@...@@...@@@@...@@@@@..     
    .@@@@@@@...@@@@...@@...@@@@...@@@@@@@.    
    .@@@@@@@@}......@@@@@@......[@@@@@@@@.    
   .@@@@@@@@@@@@@@@@------@@@@@@@@@@@@@@@@.   
   .@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@.   
 ..@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@.. 
.<<@@@@@@@@@@@@@@@@@<<<<<<@@@@@@@@@@@@@@@@@<<.
   .@@@@@@@@@@@@@@@........@@@@@@@@@@@@@@@.   
   .@@@@@@@@@@@@@@..........@@@@@@@@@@@@@@.   
    .@@@@@@@@@@@..............@@@@@@@@@@@.    
    .@@@@@@@@@@................@@@@@@@@@@.    
     ..@@@@@@@@................@@@@@@@@..     
       .@@@@@@@@@@@........@@@@@@@@@@@.       
        ..........@@@@..@@@@..........        
       ..[@@@@@@....@@@@@@....@@@@@@}..       
    .@@************@..@@..@************@@.    
    .@@************@..@@..@************@@.    
     ..%%<^^^^^^%%%........%%%^^^^^^>%%..     
         .......              .......


}