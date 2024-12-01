#include <stdio.h>


enum DayOfWeek {
    SUNDAY = 1,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY
};

enum TaskStatus {
    PENDING, // Will start at 0
    IN_PROGRESS,
    COMPLETED,
    CANCELLED
};

int main(int argc, char *argv[]) {
    enum DayOfWeek today = WEDNESDAY;
    printf("Day number of the week %d\n", today);


    enum TaskStatus status = PENDING;
    printf("\nTask Status: \n");
    printf("Initial Status: %d\n", status);

    status = COMPLETED;
    printf("Updated status: %d\n", status);

    if (status == COMPLETED) {
        printf("Task is Complete!\n");
    }

    return 0;
}