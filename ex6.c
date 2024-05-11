#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_LENGTH 10250
#define MAX_WORDS 10
#define MAX_FREQUENCY 5

// 函式宣告
typedef struct Node {
    char word[WORD_LENGTH];
    int frequency;
    int reducedFrequency; // 新增一個欄位來存儲被扣掉的頻率
    struct Node* next;
} Node;

Node* createNode(char* word);
void insert(Node** head, char* word);
void freeList(Node* head);
int search(Node* head, char* word);
void reduceFrequency(Node* head, char* word); // 新增 reduceFrequency() 函式的宣告

// 比較函式
int compare(const void *a, const void *b);

int main() {
    Node* head = NULL;

    char word[WORD_LENGTH];
    while (1) {
        fgets(word, WORD_LENGTH, stdin);   // 正確使用 fgets
        word[strcspn(word, "\n")] = '\0';  // 刪除換行字元
        if (strcmp(word, "0") == 0) {
            break;
        }

        if (word[0] == '-') {
            if (search(head, word + 1) == 0) {
                // 如果以 "-" 開頭的單字之前沒有出現過，則視為無效輸入，不需要輸出
                continue;
            } else {
                reduceFrequency(head, word + 1);  // 將 "-" 單字的頻率減少
            }
        } else {
            insert(&head, word);  // 插入新的單字
        }
    }

    // 將鏈結串列中的節點複製到一個陣列中
    Node* nodes[MAX_WORDS];
    int i = 0;
    Node* current = head;
    while (current != NULL) {
        nodes[i++] = current;
        current = current->next;
    }

    // 對陣列中的節點按照原始頻率進行排序
    qsort(nodes, i, sizeof(Node*), compare);

    // 印出排好序的節點
    for (int j = 0; j < i; j++) {
        printf("%s %d\n", nodes[j]->word, nodes[j]->frequency - nodes[j]->reducedFrequency);
    }

    // 釋放鏈結串列佔用的記憶體
    freeList(head);

    return 0;
}

Node* createNode(char* word) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    strcpy(newNode->word, word);
    newNode->frequency = 1;
    newNode->reducedFrequency = 0; // 初始化被扣掉的頻率為 0
    newNode->next = NULL;
    return newNode;
}

void insert(Node** head, char* word) {
    if (*head == NULL) {
        *head = createNode(word);
        return;
    }

    Node* current = *head;
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            current->frequency++;
            return;
        }
        if (current->next == NULL) {
            break;
        }
        current = current->next;
    }

    if (strcmp(current->word, word) != 0) {
        current->next = createNode(word);
    }
}

void freeList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int search(Node* head, char* word) {
    Node* current = head;
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            return current->frequency;
        }
        current = current->next;
    }
    return 0;
}

void reduceFrequency(Node* head, char* word) {
    Node* current = head;
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            if (current->frequency > 0) {
                current->reducedFrequency++; // 將被扣掉的頻率加一
            }
            return;
        }
        current = current->next;
    }
}

int compare(const void *a, const void *b) {
    Node *nodeA = *((Node **)a);
    Node *nodeB = *((Node **)b);
    
    // 如果兩個節點的頻率不同，按頻率降序排序
    //if (nodeA->frequency != nodeB->frequency) {
       // return nodeB->frequency - nodeA->frequency;
    //}
    
    // 如果頻率相同，按字母順序升序排序
    return strcmp(nodeA->word, nodeB->word);
}

