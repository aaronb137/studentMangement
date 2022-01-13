//Name: Aaron Bartee
//Date: 11-1-2020
//Purpose: Save and analyze from a file containing student info

#include <stdio.h>

#define FILE_NAME "students.txt"

int getMenuChoice();
void calcStats(FILE *fp, double*, double*, double*);
void saveStudents();

int main()
{
	FILE *fp;
	int userChoice;
	double min,max,avg;
	do {
		userChoice = getMenuChoice();
		switch (userChoice)
		{
		//input 1, displays file avg,min,max
		case 1: calcStats(fp, &max, &min, &avg);
			break;
		//input 2, writes new file contents		
		case 2: saveStudents(fp);
			break;
		//input 0, end program
		case 0: return 0;
		
		//if none of these, prompt user to enter valid option and end program
		default: printf("Please enter a valid option!\n\n");
			break;
		}
	   } while (userChoice != 0);

	return 0;
}

int getMenuChoice()
{
	//variable declaration
	int userChoice;
	
	//display menu
	printf("***STUDENT SYSTEM***\n");
	printf("1. Analyze Data\n");
	printf("2. Save Students\n");
	printf("0. EXIT\n");
	printf("Enter your choice: ");
	//user inputs choice
	scanf(" %d", &userChoice);
	return userChoice;
}

void calcStats(FILE *fp, double *Max, double *Min, double *Avg)
{
	double GPA, GPAtotal;
	int studentNum, GPAitems;
	// file stream
	fp = fopen(FILE_NAME, "r");
	//set assignments for if statements
	*Min = 5;
	*Max = -1;
	GPAitems = 0;
	//while loop to find min,max, and average
	
	if (fp == NULL)
	{
		printf("Cannot open file.\n");
	}
	else
	{
		while(fscanf(fp, "%d, %lf\n", &studentNum, &GPA) == 2) {
			GPAtotal = GPAtotal + GPA;
			if (GPA < *Min)
			{
				*Min = GPA; 
			}
			if (GPA > *Max)
			{
				*Max = GPA; 
			} 
		GPAitems++;
		*Avg = GPAtotal/GPAitems;
		
		}
	}
	printf("Average GPA: %.2lf\n", *Avg);
	printf("Minimum GPA: %.2lf\n", *Min);
	printf("Maximum GPA: %.2lf\n", *Max);
	
	fclose(fp);
}

void saveStudents(FILE *fp)
{
	//variable declaration
	int userAdd, baseVal, studentNum;
	double studentGPA;
	
	//file stream
	fp = fopen(FILE_NAME, "a");
	
	
	if (fp == NULL)
	{
		printf("Cannot open file.\n");
	}
	else
	{
		printf("How many students are you adding? ");
		scanf(" %d", &userAdd);
		
		for (baseVal = 1; baseVal <= userAdd; baseVal++)
		{
			printf("Enter a student number: ");
			scanf("%d", &studentNum);
			fprintf(fp, "%d,", studentNum);
			
			printf("Enter a GPA: ");
			scanf("%lf", &studentGPA);
			fprintf(fp, " %.4lf\n", studentGPA);
		}
		
		fclose(fp);
	}

}
