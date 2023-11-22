#include "SDB.h"

static student database[MAX_STUDENTS];
static uint8 usedSize = 0;

bool SDB_IsFull() {
	return usedSize == MAX_STUDENTS;
}

uint8 SDB_GetUsedSize() {
	return usedSize;
}

bool SDB_AddEntry() {
	if (usedSize >= MAX_STUDENTS) {
		return false;
	}

	student newStudent;
	printf("Enter student ID: ");
	scanf("%u", &newStudent.Student_ID);
	printf("Enter student year: ");
	scanf("%u", &newStudent.Student_year);
	printf("Enter Course1 ID: ");
	scanf("%u", &newStudent.Course1_ID);
	printf("Enter Course1 grade: ");
	scanf("%u", &newStudent.Course1_grade);
	printf("Enter Course2 ID: ");
	scanf("%u", &newStudent.Course2_ID);
	printf("Enter Course2 grade: ");
	scanf("%u", &newStudent.Course2_grade);
	printf("Enter Course3 ID: ");
	scanf("%u", &newStudent.Course3_ID);
	printf("Enter Course3 grade: ");
	scanf("%u", &newStudent.Course3_grade);

	database[usedSize] = newStudent;
	usedSize++;
	return true;
}

void SDB_DeleteEntry(uint32 id) {
    uint8 i;
    uint8 j;
	for (i = 0; i < usedSize; i++) {
		if (database[i].Student_ID == id) {
			for (j = i; j < usedSize - 1; j++) {
				database[j] = database[j + 1];
			}
			usedSize--;
			printf("Student data with ID %u deleted successfully.\n", id);
			return;
		}
	}
	printf("Student data with ID %u not found.\n", id);
}

bool SDB_ReadEntry(uint32 id) {
    uint8 i;
	for (i = 0; i < usedSize; i++) {
		if (database[i].Student_ID == id) {
			printf("Student ID: %u\n", database[i].Student_ID);
			printf("Student year: %u\n", database[i].Student_year);
			printf("Course1 ID: %u\n", database[i].Course1_ID);
			printf("Course1 grade: %u\n", database[i].Course1_grade);
			printf("Course2 ID: %u\n", database[i].Course2_ID);
			printf("Course2 grade: %u\n", database[i].Course2_grade);
			printf("Course3 ID: %u\n", database[i].Course3_ID);
			printf("Course3 grade: %u\n", database[i].Course3_grade);
			return true;
		}
	}
	return false;
}

void SDB_GetList(uint8* count, uint32* list) {
	*count = usedSize;
	uint8 i;
	for (i = 0; i < usedSize; i++) {
		list[i] = database[i].Student_ID;
	}
}

bool SDB_IsIdExist(uint32 id) {
    uint8 i;
	for (i = 0; i < usedSize; i++) {
		if (database[i].Student_ID == id) {
			return true;
		}
	}
	return false;
}
