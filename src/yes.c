#include <stdio.h>
int main(int argc, char** argv) {
    const char* str = (argc > 1) ? argv[1] : "y";
    while (1) printf("%s\n", str);
    return 0;
}