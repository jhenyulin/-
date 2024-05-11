#include <stdio.h>
#include <string.h>

#define dictMaxLength 100
#define wordsMaxLength 50

int main() {
    char dict[2][dictMaxLength][wordsMaxLength];
    char tmp[wordsMaxLength];
    int dictCountA = 0;
    int dictCountB = 0;
    char c = 0;
    char clue[wordsMaxLength];

    while ((c = getchar()) != '\n') {
        if (c == '/') {
            strcpy(dict[0][dictCountA], tmp);
            dictCountA++;
            memset(tmp, 0, sizeof(tmp));
        } else if (c == ' ') {
            if (dictCountB < dictCountA) {
                strcpy(dict[1][dictCountB], tmp);
                dictCountB++;
                memset(tmp, 0, sizeof(tmp));                
            } else {
                // 如果 dictCountB 大於 dictCountA，則將該字串加入到上一個字串中
                strcat(dict[1][dictCountB-1], " "); // 添加空格
                strcat(dict[1][dictCountB-1], tmp);
                memset(tmp, 0, sizeof(tmp)); // 清空 tmp
            }
        } else {
            tmp[strlen(tmp)] = c;
        }
    }

    scanf("%s", clue);

    int i = 0;
    while (i < dictCountA && strcmp(dict[0][i], clue) != 0) {
        i++;
    }

    if (i < dictCountA) {
        printf("%s", dict[1][i]);
    } else {
        printf("404");
    }

    return 0;
}
