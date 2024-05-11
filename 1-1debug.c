#include <stdio.h>
#include <string.h>

#define dictMaxLenth 100
#define wordsMaxLenth 50

int main() {
    char dict[dictMaxLenth];
    fgets(dict, dictMaxLenth, stdin);
    dict[strlen(dict) - 1] = '\0';  // Remove the newline character

    const char delim[] = "/ ";  // 槓跟空格都割 放一起
    int word_count = 0;

    char* word = strtok(dict, delim);
    while (word != NULL && word_count < wordsMaxLenth) {
        // 進一步分割單字
        char* subword = strtok(word, " ");
        while (subword != NULL) {
            printf("%s\n", subword); // 印出單字
            word_count++;
            subword = strtok(NULL, " "); // 取得下一個單字
        }
        word = strtok(NULL, delim); // 取得下一個分割後的字串
    }

    return 0;
}
