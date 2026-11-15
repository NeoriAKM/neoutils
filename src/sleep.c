#include <unistd.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    if (argc > 1) sleep((unsigned int)atoi(argv[1]));
    return 0;
}