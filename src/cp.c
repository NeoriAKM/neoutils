// ---------------------- //
//     cp: copy files     //
//                        //
// ?  Author: NeoriAKM  ? //
// ---------------------- //

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char* argv[]) {
    char* src = NULL;  // # file thats we need to copy
    char* dest = NULL; // # path, where we'll copy file

    if (argc < 3) {
        printf("[ERROR] Usage: %s <source> <destination>\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] != '-') {
            if (!src) src = argv[i];
            else if (!dest) dest = argv[i];
            else printf("[WARN] extra argument '%s'. I skip it\n", argv[i]);
        } else {
            printf("[WARN] sorry, args not realized yet :D\n");
        }
    }

    if (!src || !dest) {
        printf("[ERROR] Need source and destination files.\n");
        return 1;
    }

    if (strcmp(src, dest)==0) {
        printf("[ERROR] Pls don't do this. Bettr: type 2 different files.\n");
        return 1;
    }

    int src_fd = open(src, O_RDONLY);
    if (src_fd == -1) {
        perror("[ERROR] src");
        return 1;
    }

    int dest_fd = open(dest, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd == -1) {
        perror("[ERROR] dest");
        close(src_fd);
        return 1;
    }

    char buf[4096];
    ssize_t b_read;
    while ((b_read = read(src_fd, buf, sizeof(buf))) > 0) {
        write(dest_fd, buf, (size_t)b_read);
    }

    close(src_fd);
    close(dest_fd);

    return 0;
}