#include "stdafx.h"
#include <stdio.h>
#include "string.h"
#include "stdlib.h"

struct data
{
	int year;
	double tmax[12];
	double tmin[12];
	int af[12];
	double rain[12];
	double sun[12];
};

void maxTemp();
void minTemp();
void maxAF();
void maxRain();
void maxSun();

char filename[100] = "C:\\Users\\o_molloy\\suttonboningtondata.txt";
FILE *fptr;
struct data records[1000];
char months[][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
int nrecords = 0;

void main(void)
{
	int i = 0;
	char opt[10];
	int option;
	char line[400];
	int year;
	int month;
	double tmax;
	double tmin;
	int af;
	double rain;
	double sun;

	fptr = fopen(filename, "r");
	if (fptr == NULL)
	{
		puts("Cannot Open File ....exiting \n");
		return;
	}

	// use fgets to skip lines without readable data
	for (i=0;i<7;i++) fgets (line, 400, fptr);

	while (!feof(fptr))
	{
		fscanf (fptr, "%d %d %lf %lf %d %lf %lf\n", &year, &month, &tmax, &tmin, &af, &rain, &sun);
		records[nrecords].year = year;
		records[nrecords].tmax[month-1] = tmax;
		records[nrecords].tmin[month-1] = tmin;
		records[nrecords].af[month-1] = af;
		records[nrecords].rain[month-1] = rain;
		records[nrecords].sun[month-1] = sun;
		nrecords++;
	} 


	fclose (fptr);

	do
	{
		printf("Choose option: \n");
		puts("1: Temp max");
		puts("2: Temp min");
		puts("3: Air Frost Days Max");
		puts("4: Rain Max");
		puts("5: Sun Max");
		puts("0; Exit");

		scanf("%s", opt);
		opt[1] = '\0';
		option = atoi(opt);
		if (option == 1) maxTemp();
		if (option == 2) minTemp();
		if (option == 3) maxAF();
		if (option == 4) maxRain();
		if (option == 5) maxSun();
	}
	while (option != 0);


} 


void maxTemp()
{
	double maxTemp = 0.0;
	int maxMonth = 0;
	int maxYear = 0;

	int i = 0, j = 0;

	for (i=0;i<nrecords;i++)
	{
		for (j=0;j<12;j++)
		{
			if (records[i].tmax[j] > maxTemp)
			{
				maxTemp = records[i].tmax[j];
				maxMonth = j;
				maxYear = records[i].year;
			}
		}
	}

	printf ("Max Temperature was %.2lf degrees C in %s of %d \n\n", maxTemp, months[maxMonth], maxYear);
}

void minTemp()
{
	double minTemp = 0.0;
	int minMonth = 0;
	int minYear = 0;

	int i = 0, j = 0;

	for (i=0;i<nrecords;i++)
	{
		for (j=0;j<12;j++)
		{
			if (records[i].tmin[j] < minTemp)
			{
				minTemp = records[i].tmin[j];
				minMonth = j;
				minYear = records[i].year;
			}
		}
	}

	printf ("Min Temperature was %.2lf degrees C in %s of %d \n\n", minTemp, months[minMonth], minYear);
}

void maxAF()
{
	int maxAF = 0.0;
	int maxMonth = 0;
	int maxYear = 0;

	int i = 0, j = 0;

	for (i=0;i<nrecords;i++)
	{
		for (j=0;j<12;j++)
		{
			if (records[i].af[j] > maxAF)
			{
				maxAF = records[i].af[j];
				maxMonth = j;
				maxYear = records[i].year;
			}
		}
	}

	printf ("Max Air Frost Days was %d days in %s of %d \n\n", maxAF, months[maxMonth], maxYear);

}

void maxRain()
{
	double maxRain = 0.0;
	int maxMonth = 0;
	int maxYear = 0;

	int i = 0, j = 0;

	for (i=0;i<nrecords;i++)
	{
		for (j=0;j<12;j++)
		{
			if (records[i].rain[j] > maxRain)
			{
				maxRain = records[i].rain[j];
				maxMonth = j;
				maxYear = records[i].year;
			}
		}
	}

	printf ("Max Rainfall was %.2lf mm in %s of %d \n\n", maxRain, months[maxMonth], maxYear);

}

void maxSun()
{
	double maxSun = 0.0;
	int maxMonth = 0;
	int maxYear = 0;

	int i = 0, j = 0;

	for (i=0;i<nrecords;i++)
	{
		for (j=0;j<12;j++)
		{
			if (records[i].sun[j] > maxSun)
			{
				maxSun = records[i].sun[j];
				maxMonth = j;
				maxYear = records[i].year;
			}
		}
	}

	printf ("Max Sun was %.2lf hours in %s of %d \n\n", maxSun, months[maxMonth], maxYear);

}