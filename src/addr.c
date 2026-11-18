// ---------------------- //
// addr: Making directory //
//                        //
//    Author: NeoriAKM    //
// ---------------------- //
// (addr isnt address. Addr = AdDr = Add Directory)

#include <sys/stat.h>
#include <stdio.h>

int main(int argc, char** argv) {
    if (argc < 2) return 1;
    if (mkdir(argv[1], 0755) == -1) {
        perror("addr");
        return 1;
    }
    return 0;
}