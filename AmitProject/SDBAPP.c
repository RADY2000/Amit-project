#include <stdio.h>
#include "SDB.h"
#include "SDB.c"
void SDB_APP();

void SDB_action(uint8 choice) {
    uint32 id;
    uint8 count;
    uint32 list[MAX_STUDENTS];
    uint8 i;
    switch (choice) {
        case 1:
            if (SDB_AddEntry()) {
                printf("Data added successfully.\n");
            } else {
                printf("Failed to add data. Database is full or invalid input.\n");
            }
            break;
        case 2:
            printf("Used size in database: %u\n", SDB_GetUsedSize..());
            break;
        case 3:

            printf("Enter student ID to read data: ");
            scanf("%u", &id);
            if (SDB_ReadEntry(id)) {
                printf("Data found.\n");
            } else {
                printf("Data not found.\n");
            }
            break;
        case 4:
            SDB_GetList(&count, list);
            printf("List of all student IDs:\n");
            for (i = 0; i < count; i++) {
                printf("%u\n", list[i]);
            }
            break;
        case 5:
            printf("Enter student ID to check existence: ");
            scanf("%u", &id);
            if (SDB_IsIdExist(id)) {
                printf("ID exists.\n");
            } else {
                printf("ID does not exist.\n");
            }
            break;
        case 6:
            printf("Enter student ID to delete data: ");
            scanf("%u", &id);
            SDB_DeleteEntry(id);
            break;
        case 7:
            if (SDB_IsFull()) {
                printf("Database is full.\n");
            } else {
                printf("Database is not full.\n");
            }
            break;
        case 0:
            printf("Exiting the program.\n");
            return;
        default:
            printf("Invalid choice.\n");
    }
}

void SDB_APP() {
    uint8 choice;
    printf("Welcome to School Data APP.\n");
    while (1) {
        printf("Please choose one of these options.\n");
        printf("\n");
        printf("1. Add entry\n");
        printf("2. Get used size in database\n");
        printf("3. Read student data\n");
        printf("4. Get the list of all student IDs\n");
        printf("5. Check if ID exists\n");
        printf("6. Delete student data\n");
        printf("7. Check if database is full\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%hhu", &choice);

        if (choice == 0) {
            printf("Exiting the program.\n");
            break;  // Exit the while loop
        }

        SDB_action(choice);
    }
}
