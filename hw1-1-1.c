#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DICT_ENTRIES 100
#define MAX_WORD_LENGTH 50

// 结构体用于存储字典条目
struct DictEntry {
    char ancient[MAX_WORD_LENGTH];
    char modern[MAX_WORD_LENGTH];
};

int main() {
    // 定义字典数组
    struct DictEntry dictionary[MAX_DICT_ENTRIES];

    // 读取输入的字典条目
    char input[MAX_WORD_LENGTH * 2]; // 假设每个字典条目的长度不超过两倍的单词最大长度
    fgets(input, sizeof(input), stdin);

    // 解析字典条目
    int entries_count = 0;
    char *token = strtok(input, " ");
    while (token != NULL) {
        sscanf(token, "%[^/]/%s", dictionary[entries_count].ancient, dictionary[entries_count].modern);
        entries_count++;
        token = strtok(NULL, " ");
    }

    // 等待用户输入要查询的古代词
    char ancient_word[MAX_WORD_LENGTH];
    fgets(ancient_word, sizeof(ancient_word), stdin);
    // 去除查询单词的换行符
    ancient_word[strcspn(ancient_word, "\n")] = '\0';

    // 在字典中查找并打印现代字
    for (int i = 0; i < entries_count; ++i) {
        if (strcmp(dictionary[i].ancient, ancient_word) == 0) {
            printf("%s\n", dictionary[i].modern);
            break; // 找到匹配项后即可退出循环
        }
    }

    return 0;
}
