#include <stdio.h>
#include <stdlib.h>  // abs()
#include <string.h>  // strcmp()
#include <ctype.h>   // tolower()
#define maxLen 51

void lowercaseLetters(char wordsA[], char wordsB[]) {
    int i = 0;
    while (wordsA[i]) {
        wordsA[i] = tolower(wordsA[i]);
        i++;
    }
    i = 0;
    while (wordsB[i]) {
        wordsB[i] = tolower(wordsB[i]);
        i++;
    }
}

void alphabetical(char wordsA[], char wordsB[]) {
    int i = 0;
    while (wordsA[i] != '\0' && wordsB[i] != '\0') {
        if (abs(wordsA[i] - wordsB[i]) == 1) {
            wordsA[i] = wordsB[i];
        }
        i++;
    }
}

int substring(char wordsA[], char wordsB[]) {
    // Check if wordsB is a substring of wordsA
    return strstr(wordsA, wordsB) != NULL;
}

int main() {
    char wordsA[maxLen]; 
    char wordsB[maxLen];

    scanf("%50s %50s", wordsA, wordsB);

    lowercaseLetters(wordsA, wordsB);
    alphabetical(wordsA, wordsB);

    puts(strcmp(wordsA, wordsB) == 0 || substring(wordsA, wordsB) || substring(wordsB, wordsA) ? "Yes" : "No");


    return 0;
}
