//Name: Jason Chan
//Clock Program

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<conio.h>

const int MIN_TIME = 0; // min value for time
const int MAX_HOUR = 23; // max value for hour
const int MAX_MIN = 59; // max value for minute
const int MAX_SEC = 59; // max value for second
const int HOUR_TO_SEC = 3600; // hour to seconds ratio
const int MIN_TO_SEC = 60; // minute to seconds ratio
const int RESET = -1; // to reset value of time

int convert(int, int, int); // function to convert to seconds

int main()
{
	int hours, mins, secs; // hours, minutes, seconds input
	int first_input = 0; // variable to store first time input
	int second_input = 0; // variable to store second time input

	// get value of first hour input
	printf("%s%d%s%d%s","Enter the first hour value (",MIN_TIME," - ",MAX_HOUR,"): ");
	scanf("%d", &hours);
	while (hours < MIN_TIME || hours > MAX_HOUR)
	{
		printf("\nInvalid data entered, try again!\n\n");
		printf("%s%d%s%d%s", "Enter the first hour value (", MIN_TIME, " - ", MAX_HOUR, "): ");
		scanf("%d", &hours);
	} // end while
	// get value of first minute input
	printf("%s%d%s%d%s","Enter the first minute value (",MIN_TIME," - ",MAX_MIN,"): ");
	scanf("%d", &mins);
	while (mins < MIN_TIME || mins > MAX_MIN)
	{
		printf("\nInvalid data entered, try again!\n\n");
		printf("%s%d%s%d%s", "Enter the first minute value (", MIN_TIME, " - ", MAX_MIN, "): ");
		scanf("%d", &mins);
	} // end while
	// get value of first second input
	printf("%s%d%s%d%s","Enter the first second value (",MIN_TIME," - ",MAX_SEC,"): ");
	scanf("%d", &secs);
	while (secs < MIN_TIME || secs > MAX_SEC)
	{
		printf("\nInvalid data entered, try again!\n\n");
		printf("%s%d%s%d%s", "Enter the first second value (", MIN_TIME, " - ", MAX_SEC, "): ");
		scanf("%d", &secs);
	} // end while

	first_input = convert(hours, mins, secs); //store first input into var

	//reset time value
	hours, mins, secs = RESET;

	// loop until sentinel value read from user
	top:
	while (hours < MIN_TIME || hours > MAX_HOUR || 
			mins < MIN_TIME || mins > MAX_MIN || 
			secs < MIN_TIME || secs > MAX_SEC)
	{
		printf("%s%d%s%d%s", "\nEnter the second hour value (",MIN_TIME, " - ",MAX_HOUR,"): ");
		scanf("%d", &hours);
		if (hours < MIN_TIME || hours > MAX_HOUR)
		{
			printf("\nInvalid hour value entered, enter valid hour, minute and second again!\n");
			goto top; // jumps to top of loop
		}
		printf("%s%d%s%d%s", "Enter the second minute value (",MIN_TIME, " - ",MAX_MIN,"): ");
		scanf("%d", &mins);
		if (mins < MIN_TIME || mins > MAX_MIN)
		{
			printf("\n\nInvalid minute value entered, enter valid hour, minute and second again!\n");
			goto top; // jumps to top of loop
		}
		printf("%s%d%s%d%s", "Enter the second second value (",MIN_TIME, " - ",MAX_SEC,"): ");
		scanf("%d", &secs);
		if (secs < MIN_TIME || secs > MAX_SEC)
		{
			printf("\n\nInvalid second value entered, enter valid hour, minute and second again!\n");
			goto top; // jumps to top of loop
		}
	} // end while

	second_input = convert(hours, mins, secs); // store second input into var

	printf("\n\nThe first input time converted into seconds is: %d\n", first_input);
	printf("The second input time converted into seconds is: %d\n", second_input);

	printf("\nThe difference in seconds between the two input time is: %d", 
			abs(second_input - first_input));

	_getch();
	return 0;
} // end main

// function to convert hours and minutes to seconds and return a total
int convert(int hours, int mins, int secs)
{
	return (hours * HOUR_TO_SEC) + (mins * MIN_TO_SEC) + secs;
} // end function convert