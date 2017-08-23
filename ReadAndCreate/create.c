//Author: Jason Chan
 
//This application reads a CSV file, parse each line,
//and creates a binary random accces file (.dat)

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdarg.h>


struct accountDetails{
	int accountNumber;
	char firstName[100];
	char lastName[100];
	double accountBalance;
	double lastPaymentAmount;
};

typedef struct accountDetails AccountDetails;

void datFile(FILE *readPtr);

int main(void)
{
	FILE *cfPtr;

	// create clientData with default data
	AccountDetails details = { 0, "", "", 0.0, 0.0 };

	// fopen opens the file; exits if file cannot be opened
	if ((cfPtr = fopen("accounts.csv", "rb")) == NULL)
	{
		printf("File could not be opened.\n");
	} // end if
	else
	{
		printf("%-16s%s%15s%13s%15s\n", "Account Number", "First Name",
			"Last Name", "Balance", "Last Payment");

		// read all records from file (until eof)
		while (!feof(cfPtr))
		{
			fread(&details, sizeof(AccountDetails), 1, cfPtr);

			// display record
			if (details.accountNumber != 0)
			{
				printf("%-16d%s%15s%13.2f%15.2f\n"
					, details.accountNumber
					, details.firstName
					, details.lastName
					, details.accountBalance
					, details.lastPaymentAmount);
			} // end if

		} // end while

		fclose(cfPtr); // fclose closes the file
	} // end else

	datFile(cfPtr);

	puts("\nPress any key to exit...");

	_getch();

	return 0;
} //end main

void datFile(FILE *readPtr)
{
	FILE *writePtr;

	AccountDetails details = { 0, "", "", 0.0, 0.0 };

	if ((writePtr = fopen("accounts.dat", "wb")) == NULL)
	{
		printf("File could not be opened.\n");
	} // end if
	else
	{
		rewind(readPtr);
		fprintf(writePtr, "%-16s%s%15s%13s%15s\n", "Account Number",
			"First Name", "Last Name", "Balance", "Last Payment");

		while (!feof(readPtr))
		{
			fread(&details, sizeof(AccountDetails), 1, readPtr);

			// write single record to dat file
			if (details.accountNumber != 0)
			{
				fprintf("%-16d%s%15s%13.2f%15.2f\n"
					, details.accountNumber
					, details.firstName
					, details.lastName
					, details.accountBalance
					, details.lastPaymentAmount);
			} // end if

		} //end while

		fclose(writePtr); // fclose closes the file

	} // end else

} //end datFile function