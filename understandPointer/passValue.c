#include <stdio.h>

int sum(int* a) {
    return *a + 8;
}
int main() {
    int a = 5;
    int* p = &a;
    printf("Sum is: %d\n", sum(p));
    return 0;
}
