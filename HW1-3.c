#include <stdio.h>
#include <string.h>

#define LENGTH 50

int max(int a, int b) {
    return (a > b) ? a : b;
}

int compareTwoWords(char spell[], char controlGroup[]) {
    int maxLength = 0;
    int lengthOfSpell = strlen(spell);
    int lengthOfControlGroup = strlen(controlGroup);

    int longest[lengthOfSpell + 1][lengthOfControlGroup + 1];

    for (int i = 0; i <= lengthOfSpell; i++) {
        for (int j = 0; j <= lengthOfControlGroup; j++) {
            if (i == 0 || j == 0)
             longest[i][j] = 0;
            else if (spell[i - 1] == controlGroup[j - 1])
             longest[i][j] = longest[i - 1][j - 1] + 1;
            else
             longest[i][j] = 0;

            maxLength = max(maxLength, longest[i][j]);
        }
    }

    return (maxLength > 10) ? 10 : maxLength;
}

int main() {
    char spell[LENGTH];
    char controlGroup[] = "comwlkgipainrl";

    fgets(spell, sizeof(spell), stdin);

    int result = compareTwoWords(spell, controlGroup);
    printf("%d\n", result);
    return 0;
}
