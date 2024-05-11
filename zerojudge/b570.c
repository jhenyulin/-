#include <stdio.h>

int main() {
    int n = 1, a;
    scanf("%d", &a);

    while (n < a+1) {
        printf("%d. ", n);
        printf("I don't say swear words!\n");
        n++;
    }
}