#include <stdio.h>

// Function to get the day of the week for the 1st day of the month
int getFirstDayOfMonth(int year, int month) {
    int day = 1;
    int y = year - (14 - month) / 12;
    int m = month + 12 * ((14 - month) / 12) - 2;
    return (day + y + y/4 - y/100 + y/400 + (31*m)/12) % 7;
}

// Function to print the calendar for a given month and year
void printCalendar(int year, int month) {
    const char *months[] = {"January", "February", "March", "April", "May", "June",
                            "July", "August", "September", "October", "November", "December"};
    const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Check for leap year
    int days = daysInMonth[month - 1];
    if (month == 2 && (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))) {
        days = 29;
    }

    // Print the calendar header
    printf("     %s %d\n", months[month - 1], year);
    printf(" Su Mo Tu We Th Fr Sa\n");

    // Get the first day of the month
    int firstDay = getFirstDayOfMonth(year, month);

    // Print leading spaces
    for (int i = 0; i < firstDay; i++) {
        printf("   ");
    }

    // Print the days of the month
    for (int day = 1; day <= days; day++) {
        printf("%3d", day);
        if ((day + firstDay) % 7 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

int main() {
    int year, month;
    printf("Enter year: ");
    scanf("%d", &year);
    printf("Enter month (1-12): ");
    scanf("%d", &month);

    if (month < 1 || month > 12) {
        printf("Invalid month. Please enter a value between 1 and 12.\n");
        return 1;
    }

    printCalendar(year, month);
    return 0;
}