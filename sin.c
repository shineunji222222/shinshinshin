#include <stdio.h>

int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int getDaysInMonth(int month, int year) {
    switch (month) {
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return isLeapYear(year) ? 29 : 28;
        default:
            return 31;
    }
}

void printCalendar(int year) {
    const char *months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    const char *days[] = {
        "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"
    };

    int dayOfWeek = 0; // Assuming the year starts on a Sunday

    for (int month = 1; month <= 12; month++) {
        printf("\n  ------------%s-------------\n", months[month - 1]);
        for (int i = 0; i < 7; i++) {
            printf("%s ", days[i]);
        }
        printf("\n");

        int daysInMonth = getDaysInMonth(month, year);
        for (int i = 0; i < dayOfWeek; i++) {
            printf("    ");
        }

        for (int day = 1; day <= daysInMonth; day++) {
            printf("%3d ", day);
            if (++dayOfWeek > 6) {
                dayOfWeek = 0;
                printf("\n");
            }
        }
        if (dayOfWeek != 0) {
            printf("\n");
        }
    }
}

int main() {
    int year;
    printf("Enter year: ");
    scanf("%d", &year);
    printCalendar(year);
    return 0;
}