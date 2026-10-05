#include <iostream>
// #include <fstream>
#include <string>
#include "../nugl.h"

int main(int argc, char *argv[]) {
    char *filename = NULL;
    FILE *file = NULL;
    const std::string color1 = "\033[32m";
    const std::string color2 = "\033[34m";
    const std::string endc = "\033[0m";

    bool showall = false;
    bool nums = false;
    bool empty = false;
    
    const char* tab = "----------------------------------------------\n";
    std::string ctab= color1+"--------------------------------------------------------\n"+endc;


    if (argc < 2) {
        std::cout << "usage: dog <file>\n";
        return 1;
    } else {
        for (int i = 1; i < argc; i++) {
            if (cmp(argv[i], "--version") == 0) {            // version
                std::cout << tab;
                std::cout << "dog v1.1 | By "<<color1<<"Neori"<<endc<<" | Made for "<<color2<<"ProgwiLinux\n"<<endc;
                std::cout << tab;
                std::cout << "Program for reading a files.\nAnalog of 'cat' from UNIX.\nExperimental version on C++\n";
                std::cout << tab;
                return 0;
            } else if (cmp(argv[i], "-a") == 0) {            // all
                showall = 1;
            } else if (cmp(argv[i], "-n") == 0) {            // nums
                nums = 1;
            } else if (cmp(argv[i], "-e") == 0) {            // empty
                empty = 1;
            } else if (cmp(argv[i], "--help") == 0) {        // help
                std::cout << color2 << "                     Usage of dog        \n" << endc;
                std::cout << ctab;
                std::cout << "dog <path>         shows folders and files from that folder\n";
                std::cout << "\n";
                std::cout << "                    " << color2 << "Flags/arguments\n";
                std::cout << ctab;
                std::cout << " -a      all        removing barier to files 500+ stringlines\n";
                std::cout << " --version          prints info about dog\n";
                std::cout << " --help             opening this reference\n";
                std::cout << " -n     nums        add string nums on left side\n";
                std::cout << " -e    empty        removing empty strings";
                std::cout << ctab;
                return 0;
            } else if (argv[i][0] != '-') {
                filename = argv[i];
            } else {
                std::cout << "Unknown flag. --help for reference\n";
                return 1;
            }
        }
    }

    if (filename == NULL) {std::cout << "No file specified. usage: dog <file>\n"; return 1;}

    file = fopen(filename, "r");
    if (file == NULL) {
        perror("fopen");
        return 1;
    }


    int line_num = 1;
    char line[512];
    while (fgets(line, sizeof(line), file) != NULL) {

        if (empty == 1 && cmp(line, "\n") == 0) {line_num++; continue;}

        if (nums == 0) {printf("%s", line);}
        else {std::cout << color1 << line_num << endc << ". " << line;}


        line_num++;

        if (line_num > 500 && showall == 0) {
            std::cout << "\n...\n";
            fclose(file);
            return 0;
        }

    }
    fclose(file);
    return 0;
}