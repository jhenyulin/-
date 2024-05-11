#include <stdio.h>
#include <string.h>

int main() {
    char Operation[16];
    long int num, result = 0;

    scanf("%s", Operation);

    if (strcmp(Operation, "Addition") == 0 ||
        strcmp(Operation, "Multiplication") == 0 ||
        strcmp(Operation, "Subtraction") == 0) {
        int scanned = scanf("%ld", &result);

        if (scanned == 1) {
            while (1) {
                int scanned = scanf("%ld", &num);
                if (scanned == 1) {
                    if (strcmp(Operation, "Addition") == 0) {
                        result += num;
                    } else if (strcmp(Operation, "Multiplication") == 0) {
                        result *= num;
                    } else if (strcmp(Operation, "Subtraction") == 0) {
                        result -= num;
                    }
                } else {
                    int ch = getchar();
                    if (ch == '/') {
                        // 如果成功讀取到 "/"，繼續下一輪迴圈
                        continue;
                    } else if (ch == '\n') {
                        // 如果讀取換行符（Enter），退出迴圈
                        break;
                    } else {
                        break;
                    }
                }
            }
        } else {
            // 錯誤處理，清空輸入緩衝區
            while (getchar() != '\n')
                ;
        }
    }

    printf("%ld", result);

    return 0;
}
