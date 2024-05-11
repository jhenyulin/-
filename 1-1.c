#include <stdio.h>
#include <string.h>

#define dictMaxLenth 100
#define wordsMaxLenth 50

int main() {
    
    char dict[dictMaxLenth];
    fgets(dict, dictMaxLenth, stdin);
    dict[strlen(dict) - 1] = '\0'; // Remove the newline character

    
    const char delim[] = "/ "; // 槓跟空格都割 放一起
    const char* words[wordsMaxLenth];
    int word_count = 0;

    char* word = strtok(dict, delim);
    int i = 0;
    while (word != NULL && i < wordsMaxLenth) {
        words[i] = word;
        i++;

        word = strtok(NULL, delim);
                                    // 原型 char *strtok(char *str, const char
                                    // *delim); 切完存起來下次繼續切割
        if (word != NULL && i < wordsMaxLenth) {            
            char separator[] = "/";                       //沒用separator會出錯  
            words[i] = separator;
            i++;
        }
    }
    word_count = i; // Store the actual word count
    
    char index[wordsMaxLenth];
    scanf("%s", index);
    //for(int i = 0;i<10;i++){
    //    printf("%s %d\n",words[i],i);
   // }

   
    int counts = word_count-1; // Subtracting one because array indexing starts from 0

   
    int found = 0; // Flag 404
    while (counts >= 0) {
        
        if (strcmp(index, words[counts]) == 0) {
            found = 1; // Set flag to indicate word is found
          
            if (counts + 5 < word_count && strcmp("/", words[counts + 5]) == 0 && counts + 4 < word_count) {
               
                printf("%s %s\n", words[counts + 2], words[counts + 4]);
            } else printf("%s\n", words[counts + 2]);
            
            break; 
        } else {
            
            counts--;
        }
    }

    if (!found) printf("404\n");
    

    return 0;
}
