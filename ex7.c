#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* longest_common_prefix(int case_sensitive, char** words, int num_words) {
    if (num_words == 0) {
        return "No longest common prefix";
    }
    
    char* prefix = (char*)malloc(sizeof(char) * 101); // Assuming max word length is 100
    int i, j;
    for (i = 0; words[0][i] != '\0'; i++) {
        // Check if all characters at position i are the same
        for (j = 1; j < num_words; j++) {
            if ((case_sensitive == 1 && words[0][i] != words[j][i]) ||
                (case_sensitive == 2 && tolower(words[0][i]) != tolower(words[j][i]))) {
                break;
            }
        }
        if (j < num_words) {
            break;
        }
        prefix[i] = words[0][i];
    }
    prefix[i] = '\0';
    
    if (strlen(prefix) > 0) {
        // If case-insensitive option and the common prefix has both lowercase and uppercase,
        // output lowercase for the answer
        if (case_sensitive == 2) {
            int has_lowercase = 0;
            int has_uppercase = 0;
            for (i = 0; prefix[i] != '\0'; i++) {
                if (islower(prefix[i])) {
                    has_lowercase = 1;
                }
                if (isupper(prefix[i])) {
                    has_uppercase = 1;
                }
            }
            if (has_lowercase && has_uppercase) {
                for (i = 0; prefix[i] != '\0'; i++) {
                    prefix[i] = tolower(prefix[i]);
                }
            }
        }
        return prefix;
    } else {
        return "No longest common prefix";
    }
}

int main() {
    int case_option;
   
    scanf("%d", &case_option);
    
    int num_words;
   
    scanf("%d", &num_words);
    
    char** words = (char**)malloc(sizeof(char*) * num_words);
    for (int i = 0; i < num_words; i++) {
        words[i] = (char*)malloc(sizeof(char) * 101); // Assuming max word length is 100
        
        scanf("%s", words[i]);
    }
    
    char* result = longest_common_prefix(case_option, words, num_words);
    printf("%s\n", result);
    
    // Free allocated memory
    for (int i = 0; i < num_words; i++) {
        free(words[i]);
    }
    free(words);
    
    return 0;
}
