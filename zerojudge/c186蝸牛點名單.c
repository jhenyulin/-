#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main() {
    char ch;
    int flag = 1;

    while ((ch = getchar()) != EOF) {
        if (flag && ch != ' ' && ch != '\n') {
            ch = toupper(ch);
            flag = 0;
        }

        if (ch == '\n') {
            flag = 1;
        }

        printf("%c", ch);

        if (ch == ' ') {
            printf("\n");
            flag = 1;
        }
    }

    return 0;
}
