#include <stdio.h>
#include <string.h>

void rotate_string(char *input_str) {
    int i, j, n;
    char temp;
    n = strlen(input_str);
    for (i = 0; i < n; i++) {
        printf("%s\n", input_str);
        temp = input_str[0];
        for (j = 0; j < n - 1; j++) {
            input_str[j] = input_str[j + 1];
        }
        input_str[n - 1] = temp;
    }
}

int main() {
    char input_str[100];
    scanf("%s", input_str);
    rotate_string(input_str);
    return 0;
}
