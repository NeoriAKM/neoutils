#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

int main() {
    struct passwd *pw = getpwuid(getuid());
    if (pw == NULL) {
        fprintf(stderr, "[ERROR] Cannot find name for user with ID: %d\n", getuid());
        return 1;
    }
    printf("%s\n", pw->pw_name);
    return 0;
}