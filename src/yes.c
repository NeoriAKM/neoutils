#include <unistd.h>

size_t strlen(const char *s) {
    const char *p = s;
    while (*p) p++;
    return p - s;
}

int main(int argc, char* argv[]) {
    while (true) write(1, "y\n", strlen("yes"));
    return 0;
}