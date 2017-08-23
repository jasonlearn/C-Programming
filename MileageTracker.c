//Name: Jason Chan

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main()
{
	int miles, miles1;  //integer miles
	float gallon, gallon1, averageMilesPerGallon, totalAverageMilesPerGallon; //float gallon
	const EXIT = -1; //constant exit

	miles = 0; //set inital value to miles
	gallon = 0; //sets inital value to gallon
	totalAverageMilesPerGallon = 0; //set inital value to totalAverageMilesPerGallon

	printf("Enter the gallons used (%d to ends): ", EXIT); //message to enter gallon
	scanf("%f", &gallon1); //prompt for gallon input

	while (gallon1 != EXIT) //while loop for multiple inputs
	{
		gallon += gallon1; //adds gallon input to total gallons
		printf("Enter the miles driven: "); //message to enter miles driven
		scanf("%d", &miles1); //prompts for miles driven
		miles += miles1; //adds mile input to total miles
		averageMilesPerGallon = miles1 / gallon1; //calculate average for current input
		printf("The miles/gallon for this tank was %f\n\n", averageMilesPerGallon); //displays average miles/gallon for current input
		totalAverageMilesPerGallon = miles / gallon; //calculates total average miles/gallon
		printf("Enter the gallons used (%d to ends): ", EXIT); // message to enter gallon
		scanf("%f", &gallon1); // prompts for gallon input
	} //end while loop

	if (totalAverageMilesPerGallon == 0)
	{
		printf("\nThe overall average miles / gallon could not be computed ;-(\n\n"); //displays if input equals EXIT
	}
	else
	{
		printf("\nThe overall average miles / gallon was %f\n", totalAverageMilesPerGallon); //displays a message of total avera miles/gallon for all inputs
	}
		puts("\nThat's all folks - press any key to exit\n"); //message to exit this application

	_getch();
	return 0;
} //end main