#include <unistd.h>
int main() {write(1, "\033[3J\033[H\033[2J", 11); return 0;}