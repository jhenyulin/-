/*#include <stdio.h>

int main() {
    int num, array[500];
    array[0] = 1;

    while (scanf("%d", num) != EOF) {
        for (int i = 1; i < num; i++) {
            array[i] = array[i - 1] + i;
        }
        printf("%d", array[num]);
    }
}*/
#include <stdio.h>

int main() {
    int num, array[500];
    array[0] = 1;

    while (scanf("%d", &num) != EOF) { 
        for (int i = 1; i < num+1; i++) {
            array[i] = array[i - 1] + (i - 1); 
        }
        printf("%d\n", array[num]); 
    }

    return 0; 
}
