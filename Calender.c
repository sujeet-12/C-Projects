#include <stdio.h>

// Function to check if a year is a leap year
int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return 1;
    return 0;
}

// Function to get the number of days in a month
int getDaysInMonth(int month, int year) {
    switch(month) {
        case 1: return 31;
        case 2: return isLeapYear(year) ? 29 : 28;
        case 3: return 31;
        case 4: return 30;
        case 5: return 31;
        case 6: return 30;
        case 7: return 31;
        case 8: return 31;
        case 9: return 30;
        case 10:return 31;
        case 11:return 30;
        case 12:return 31;
        default:return 0;
    }
}

// Function to calculate the day of the week for the 1st of the month
int getStartingDay(int month, int year) {
    int d = 1, m = month, y = year;

    if (m < 3) {
        m += 12;
        y -= 1;
    }

    int k = y % 100;
    int j = y / 100;

    int day = (d + 13*(m+1)/5 + k + k/4 + j/4 + 5*j) % 7;
    return (day + 6) % 7; // to adjust for Sunday=0, Monday=1, etc.
}

// Main function
int main() {
    int month, year;

    printf("Enter month (1-12): ");
    scanf("%d", &month);

    printf("Enter year: ");
    scanf("%d", &year);

    printf("\nCalendar for %d/%d\n", month, year);
    printf("Sun Mon Tue Wed Thu Fri Sat\n");

    int startDay = getStartingDay(month, year);
    int days = getDaysInMonth(month, year);

    for (int i = 0; i < startDay; i++)
        printf("    ");

    for (int day = 1; day <= days; day++) {
        printf("%3d ", day);
        if ((day + startDay) % 7 == 0)
            printf("\n");
    }

    printf("\n");
    return 0;
}
