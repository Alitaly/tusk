// Week14.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"

struct date
{
	int day, month, year;
};

struct student
{
	int studentID;
	char firstName[20];
	char lastName[20];
	char courseID[10];
	int year;
	struct date registrationDate;
	struct date dateOfBirth;
	int averageGrade;
};

int main()
{
	struct student students[100];
	int numStudents = 0;
	int i = 0;
	FILE * fptr;

	fptr = fopen( "c:\\Users\\o_molloy\\students.txt", "r" );

	if (fptr == NULL)
	{
		puts ("Error opening file - exiting");
		return 0;
	}

	puts ("Reading data file");

	while (!feof(fptr))
	{
		fscanf(fptr, "%d %s %s %s %d %d %d %d %d %d %d", &students[i].studentID, students[i].firstName, students[i].lastName, students[i].courseID, &students[i].year, &students[i].registrationDate.day, &students[i].registrationDate.month, &students[i].registrationDate.year, &students[i].dateOfBirth.day, &students[i].dateOfBirth.month, &students[i].dateOfBirth.year);
		i++;
		numStudents++;
	}

	fclose(fptr);


	printf("\n\n");

	for (i=0; i<numStudents; i++)
	{
		students[i].averageGrade = rand() % 101;
	}

	fptr = fopen( "c:\\Users\\o_molloy\\students.txt", "w" );

	if (fptr == NULL)
	{
		puts ("Error opening file for writing - exiting");
		return 0;
	}

	puts ("Writing data file");

	for (i=0; i<numStudents; i++)
	{
		fprintf(fptr, "%d %s %s %s %d %d %d %d %d %d %d %d\n", students[i].studentID, students[i].firstName, students[i].lastName, students[i].courseID, students[i].year, students[i].registrationDate.day, students[i].registrationDate.month, students[i].registrationDate.year, students[i].dateOfBirth.day, students[i].dateOfBirth.month, students[i].dateOfBirth.year, students[i].averageGrade);
	}

	fclose(fptr);

	puts ("Finished");

	return 0;
}
