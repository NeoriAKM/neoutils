#include <stdio.h>
#include <string.h>

int main() {
    char input[256];

    char* utils_list[] = {
        "(a) addr",
        "(c) clear",
        "(C) cp",
        "(d) dog",
        "(e) echo",
        "(f) false",
        "(l) lsdr",
        "(m) myname",
        "(s) sleep",
        "(S) strc",
        "(t) true",
        "(w) wai",
        "(y) yes",
        NULL
    }; char** utils = utils_list;

    printf("\033[3J\033[H\033[2J");
    fflush(stdout);
    printf("--------------- Neoutils Hub ---------------\n");

    printf(""
        "  (u)tils\n"
        "  (c)redits\n\n"
    );
    printf("print letter from the list: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    if (strcmp(input, "u")==0) {
        printf("\nUtils information page\n");
        for (int i = 0; utils[i] != NULL; i++) {
            printf("%s\n", utils[i]);
        }
        printf("print letter from the list: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "a")==0) {
            printf(""
                "\n  Info about addr\n"
                "--------------- Flags ---------------\n"
                " AdDr has no flags yet :/\n"
                "--------- Basic functional ----------\n"
                " Making directory. that's why it's\n"
                "called \"Add Dir\"\n"
                "-------------------------------------\n"
            );
        } if (strcmp(input, "c")==0) {
            printf(""
                "\n  Info about clear\n"
                "--------------- Flags ---------------\n"
                " Clear has no flags yet :/\n"
                "--------- Basic functional ----------\n"
                " Clears your shell\n"
                "-------------------------------------\n"
            );
        } else printf("Coming soon...\n");
    } else if (strcmp(input, "c")==0) {
        printf(""
            "--------------- Credits ---------------\n"
            " -    Version     -      Beta 2.0    -\n"
            " -  Hub version   -      Alpha 0.1   -\n"
            "---------------------------------------\n"
            " -    NeoriAKM    -  Main developper -\n"
            " -    Utils for   -    Progwilinux   -\n"
            "---------------------------------------\n"
        );
    }

    return 0;
}