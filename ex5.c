#include <stdio.h>
#include <string.h>

struct Student {
    char name[21]; // 將 name 的大小從 20 變更為 21
    int score;
};

void sortStudents(struct Student students[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].score < students[j + 1].score ||
                (students[j].score == students[j + 1].score &&
                 strcmp(students[j].name, students[j + 1].name) > 0)) {
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    struct Student students[n];
    for (int i = 0; i < n; i++) {
        scanf("%20s %d", students[i].name, &students[i].score); // 將 %s 改為 %20s
    }

    sortStudents(students, n);

    for (int i = 0; i < n; i++) {
        printf("%s %d\n", students[i].name, students[i].score);
    }

    return 0;
}
