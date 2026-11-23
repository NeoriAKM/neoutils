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

        printf("Coming soon...\n");
    }

    return 0;
}