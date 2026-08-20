#include <unistd.h>

int main(int argc, char* argv[]) {
    while (true) write(1, "y\n", 2);
    return 0;
}