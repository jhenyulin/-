#include <stdio.h>
#include <string.h>

#define dictMaxLenth 100
#define wordsMaxLenth 50

int main() {
    char dict[dictMaxLenth];
    fgets(dict, dictMaxLenth, stdin);

    // 在输入的字符串末尾添加一个空字符 '\0'
    dict[strlen(dict) - 1] = '\0';

    const char delim[] = "/ ";  // 槓跟空格都割 放一起
    const char* words[wordsMaxLenth];
    int word_count = 0;

    char* word = strtok(dict, delim);
    while (word != NULL && word_count < wordsMaxLenth) {
        words[word_count] = word;
        word_count++;

        word = strtok(NULL, delim);  // 原型 char *strtok(char *str, const char
                                     // *delim); 切完存起來下次繼續切割
        //沒用separator會出錯                            
        if (word != NULL && word_count < wordsMaxLenth) {
            char separator[] = "/";  
            words[word_count] = separator;  
            word_count++;
        }
    }

    char index[wordsMaxLenth];
    scanf("%s", index);
    while (word_count >= 0) {
        word_count--;  // 先將 word_count 減少，再檢查
        if (strcmp(index, words[word_count]) == 0) {
            if (not (strcmp("/", words[word_count+3]) == 0 && strcmp(NULL, words[word_count+3]) == 0)){
                if (strcmp(index, words[word_count]) == 0) {
                    printf("%s %s",words[word_count],words[word_count+3]);
                }
            }else printf("%s",words[word_count+2]);
            
            break;  // 找到匹配的單詞後退出迴圈
        }
        else puts("404");
    }
   
   return 0;
}
