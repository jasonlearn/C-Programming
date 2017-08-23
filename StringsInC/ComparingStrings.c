//Comparing portions of Strings
//Author: Jason Chan A00698160

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	//initialize array string
	char string1[100], string2[100];

	//create variable to compare strings
	int comparison;

	//prompt user for first string input
	printf("Input the first string:\n\n");
	gets(string1);

	//prompt user for second string input
	printf("\nInput the second string:\n\n");
	gets(string2);

	//display the two strings being compared
	printf("\nCompare strings:\n");
	printf("\t\t\t%s\n", &string1);
	printf("\t\t\t%s\n", &string2);
	
	//to determine the shorter length of the two strings
	//and use that length to compare
	if (strlen(string1) <= strlen(string2))
	{
		comparison = strlen(string1); //use string1 length to compare
	}
	else
	{
		comparison = strlen(string2); //use string2 length to compare
	} //end if else statement

	//compares the two string to see if string1 is equal, greater or less than string2
	if (!strncmp(string1, string2, comparison))
	{
		printf("\nResult: String 1 is equal to String 2\n");
	}
	else if (strncmp(string1, string2, comparison) > 0)
	{
		printf("\nResult: String 1 is greater than String 2\n");
	}
	else{
		printf("\nResult: String 1 is less than String 2\n");
	} // end if else statement

	puts("");

	_getch();
	return 0;
} //end main
