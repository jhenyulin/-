#include <stdio.h>
#include <string.h>

enum week {
    Sunday,
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday
};

int main() {
    char day[20]; 

    scanf("%s", day);

    int dayIndex = -1;

    if (strcmp(day, "Sunday") == 0) {
        dayIndex = Sunday;
    } else if (strcmp(day, "Monday") == 0) {
        dayIndex = Monday;
    } else if (strcmp(day, "Tuesday") == 0) {
        dayIndex = Tuesday;
    } else if (strcmp(day, "Wednesday") == 0) {
        dayIndex = Wednesday;
    } else if (strcmp(day, "Thursday") == 0) {
        dayIndex = Thursday;
    } else if (strcmp(day, "Friday") == 0) {
        dayIndex = Friday;
    } else if (strcmp(day, "Saturday") == 0) {
        dayIndex = Saturday;
    }

    if (dayIndex != -1) {
        printf("%d\n", dayIndex);
    } else {
        printf("error\n");
    }

    return 0;
}
