#include <stdio.h>

int main() {
    int dir, b, x = 0, y = 0, N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &dir, &b);
        switch (dir) {
            case 0:
                y = y + b;
                break;
            case 1:
                x = x + b;
                break;
            case 2:
                y = y - b;
                break;
            case 3:
                x = x - b;
                break;
        }
    }
    printf("%d %d", x, y);
}