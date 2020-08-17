//***************************************
//Bello abarchi
//Date 11/04/2017
//Professor: Dennis Hunchuck
//***************************************
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define PAUSE getchar()
#define CLS system("cls")
#define FLUSH myFlush();
#define SIZE 100

typedef struct {
	char name[20];
	float exam1;
	float exam2;
	float exam3;
	float exam4;
} STUDENT;

// function prototype
void myFlush();
char getChoice();
void displayMenu();
void loadCars(STUDENT student[], int *studentCounter);
void save(STUDENT student[], int studentCounter);
void displayClassAverage(STUDENT student[], int studentCounter);
void getStudent(STUDENT student[], int studentCounter);
void getName(STUDENT student[], int studentCounter);
void getExam1(STUDENT student[], int studentCounter);
void getExam2(STUDENT student[], int studentCounter);
void getExam3(STUDENT student[], int studentCounter);
void getExam4(STUDENT student[], int studentCounter);
void displayStudent(STUDENT student[], int studentCounter);
void displayStudentAverage(STUDENT student[], int studentCounter);
void myFlush();
main() {
	//Variable Declaration

	char choice;
	int studentCounter = 0;
	STUDENT student[SIZE];
	FILE *ptr;
	ptr = fopen("StoredStudent.bin", "rb");
	if (ptr != NULL)
		loadCars(student, &studentCounter);
	//Menu System
	do {
		choice = getChoice();
		switch (choice) {
		case 'A'://add new client
			if (studentCounter < 100) {
				getStudent(student, studentCounter);
				studentCounter++;
			}
			else {
				printf("Cannot enter any more cars\n");
				PAUSE;
			}
			break;
		case 'B'://display all students
			if (studentCounter > 0) {
				displayStudent(student, studentCounter);
			}
			else {
				printf("No cars have been entered yet!\n");
				PAUSE;
			}
			break;
		case 'C'://save file
			if (studentCounter > 0) {
				save(student, studentCounter);
				printf("Successfully Saved!\n");
				PAUSE;
			}
			else {
				printf("No student has been entered yet!\n");
				PAUSE;
			}
			break;
		case 'D'://display class average 
			if (studentCounter > 0) {
				displayClassAverage(student, studentCounter);
			}
			else {
				printf("No student has been entered yet!\n");
				PAUSE;
			}
			break;
		case 'E'://display class average 
			if (studentCounter > 0) {
				displayStudentAverage(student, studentCounter);
			}
			else {
				printf("No student has been entered yet!\n");
				PAUSE;
			}
			break;
		case 'Q':// Quits the program
			printf("\t=======================================\n");
			printf("\t===========HAVE A NICE DAY!============\n");
			printf("\t=======================================\n");
			PAUSE;
			break;
		default:
			break;
		}//end switch
	} while (choice != 'Q');

}//end main

void displayMenu() {
	CLS;
	printf("\t=======================================\n");
	printf("\t==         M A I N   M E N U         ==\n");
	printf("\t=======================================\n");
	printf("\t[A] Add new student\n");
	printf("\t[B] Display all student\n");
	printf("\t[C] Save all student\n");
	printf("\t[D] Display class avg\n");
	printf("\t[E] Display student avg\n");
	printf("\t[Q] Quit \n");
	printf("\t=======================================\n");
	printf("\tEnter choice: ");
}//end displayMenu


char getChoice() {
	char choice;
	displayMenu();
	scanf(" %c", &choice); FLUSH;

	return toupper(choice);
}//end getChoice

void loadCars(STUDENT student[], int *studentCounter) {
	FILE *ptr;
	ptr = fopen("StoredCars.bin", "rb");

	if (ptr == NULL) {
		printf("Error Loading cars no cars to load\n");
		PAUSE;
	}
	else {
		fread(student, sizeof(STUDENT), SIZE, ptr);
		fread(&*studentCounter, sizeof(int), 1, ptr);
	}
	fclose(ptr);
}//end load cars

void save(STUDENT student[], int studentCounter) {
	FILE *ptr;
	ptr = fopen("StoredCars.bin", "wb");
	if (ptr == NULL) {
		printf("\nError Could not save cars\n");
		PAUSE;
		exit(-1);
	}
	else {
		fwrite(student, sizeof(STUDENT), SIZE, ptr);
		fwrite(&studentCounter, sizeof(int), 1, ptr);
	}
	fclose(ptr);

}// end save 
void displayClassAverage(STUDENT student[], int studentCounter) {
	CLS;
	int i = 0;
	float averageGrade = 0;
	float totalGrade = 0;
	printf("=================================================\n");
	printf("===============DISPLAY CLASS AVERAGE=============\n");
	printf("=================================================\n");
	for (i = 0; i < studentCounter; i++) {
		totalGrade += student[i].exam1 + student[i].exam2 + student[i].exam3 + student[i].exam4;
	}

	averageGrade = totalGrade / studentCounter;
	printf("=================================================\n");
	printf("There are %i student(s)\n", studentCounter);
	printf("Average student grade: %.2f points \n", averageGrade);
	printf("=================================================\n");
	PAUSE;
} //End displayData

void getStudent(STUDENT student[], int studentCounter) {
	getName(student, studentCounter);
	getExam1(student, studentCounter);
	getExam2(student, studentCounter);
	getExam3(student, studentCounter);
	getExam4(student, studentCounter);
}
void getName(STUDENT student[], int studentCounter) {
	CLS;
	printf("=================================================\n");
	printf("student Name: \n");
	scanf("%s", &student[studentCounter].name); FLUSH;
};
void getExam1(STUDENT student[], int studentCounter) {
	CLS;
	printf("=================================================\n");
	printf("Enter grade for  exam 1: \n");
	scanf("%f", &student[studentCounter].exam1); FLUSH;
	while (student[studentCounter].exam1 < 0 || student[studentCounter].exam1 > 100) {
		CLS;
		printf("Error invalid grade\n");
		printf("Enter grade 1 of the student: \n");
		scanf("%f", &student[studentCounter].exam1); FLUSH;
	}
}

void getExam2(STUDENT student[], int studentCounter) {
	CLS;
	printf("=================================================\n");
	printf("Enter grade for  exam 2: \n");
	scanf("%f", &student[studentCounter].exam2); FLUSH;
	while (student[studentCounter].exam2 < 0 || student[studentCounter].exam2 > 100) {
		CLS;
		printf("Error invalid grade\n");
		printf("Enter grade 2 of the student: \n");
		scanf("%f", &student[studentCounter].exam2); FLUSH;
	}
}


void getExam3(STUDENT student[], int studentCounter) {
	CLS;
	printf("=================================================\n");
	printf("Enter grade for  exam 3: \n");
	scanf("%f", &student[studentCounter].exam3); FLUSH;
	while (student[studentCounter].exam3 < 0 || student[studentCounter].exam3 > 100) {
		CLS;
		printf("Error invalid grade\n");
		printf("Enter grade 3 of the student: \n");
		scanf("%f", &student[studentCounter].exam3); FLUSH;
	}
}

void getExam4(STUDENT student[], int studentCounter) {
	CLS;
	printf("=================================================\n");
	printf("Enter grade for  exam 4: \n");
	scanf("%f", &student[studentCounter].exam4); FLUSH;
	while (student[studentCounter].exam4 < 0 || student[studentCounter].exam4 > 100) {
		CLS;
		printf("=================================================\n");
		printf("Error invalid grade\n");
		printf("Enter the grade of the student: \n");
		scanf("%f", &student[studentCounter].exam4); FLUSH;
	}
}

void displayStudent(STUDENT student[], int studentCounter) {
	CLS;
	int i;
	printf("=================================================\n");
	printf("=================DISPLAY STUDENTS================\n");
	printf("=================================================\n");
	for (i = 0; i < studentCounter; i++) {
		
		printf("%s\n", student[i].name);
		printf("%.2lf\n", student[i].exam1);
		printf("%.2lf\n", student[i].exam2);
		printf("%.2lf\n", student[i].exam3);
		printf("%.2lf\n", student[i].exam4);
		printf("=================================================\n");
	} // end for
	PAUSE;
} // end displayResults

void myFlush() {
	char nothing;
	while (scanf("%c", &nothing) == NULL);
}
void displayStudentAverage(STUDENT student[], int studentCounter) {
	CLS;
	int i = 0;
	float averageGrade = 0;
	float totalGrade = 0;
	printf("=================================================\n");
	printf("==============DISPLAY STUDENT AVERAGE============\n");
	printf("=================================================\n");
	for (i = 0; i < studentCounter; i++) {
		
		printf("%s\n", student[i].name);
		printf("%.2lf\n", student[i].exam1);
		printf("%.2lf\n", student[i].exam2);
		printf("%.2lf\n", student[i].exam3);
		printf("%.2lf\n", student[i].exam4);
		totalGrade += student[i].exam1 + student[i].exam2 + student[i].exam3 + student[i].exam4;

		averageGrade = totalGrade / 4;
		printf("Average student grade: %.2f points \n", averageGrade);
		printf("=================================================\n");
	}//end of displaySt
	PAUSE;
	}//end of for 
	