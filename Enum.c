#include <stdio.h>

// 定義一個枚舉類型，名為 Weekday
enum Weekday {
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};

int main() {
    // 創建一個 Weekday 類型的變量，並賦值為 MONDAY
    enum Weekday today = MONDAY;

    // 使用 switch 來處理不同的枚舉值
    switch (today) {
        case MONDAY:
            printf("Today is Monday.\n");
            break;
        case TUESDAY:
            printf("Today is Tuesday.\n");
            break;
        case WEDNESDAY:
            printf("Today is Wednesday.\n");
            break;
        case THURSDAY:
            printf("Today is Thursday.\n");
            break;
        case FRIDAY:
            printf("Today is Friday.\n");
            break;
        case SATURDAY:
            printf("Today is Saturday.\n");
            break;
        case SUNDAY:
            printf("Today is Sunday.\n");
            break;
        default:
            printf("Invalid day.\n");
    }

    return 0;
}
