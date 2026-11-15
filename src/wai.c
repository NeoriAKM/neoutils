#include <stdio.h>
#include <unistd.h>
int main() {
    char buf[1024];
    if (getcwd(buf, sizeof(buf)) != NULL) printf("%s\n", buf);
    return 0;
}