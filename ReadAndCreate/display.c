//Author: Jason Chan A00698160
 
//This application reads a CSV file, parse each line,
//and creates a binary random accces file (.dat)

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>

const int SIZE = 100;

struct accountDetails{
	int accountNumber;
	char firstName[100];
	char lastName[100];
	double accountBalance;
	double lastPaymentAmount;
};

typedef struct accountDetails AccountDetails;

int main(void)
{
	FILE *cfPtr;

	// create clientData with default data
	AccountDetails details = { 0, "", "", 0.0, 0.0 };

	// fopen opens the file; exits if file cannot be opened
	if ((cfPtr = fopen("accounts.dat", "rb")) == NULL)
	{
		printf("File could not be opened.\n");
	}
	else
	{
		printf("%-6s%-16s%-11s%10s%10s\n", "Acc Number", "First Name",
			"Last Name", "Balance", "Last Payment");

		// read all records from file (until eof)
		while (!feof(cfPtr))
		{
			fread(&details, sizeof(AccountDetails), 1, cfPtr);

			// display record
			if (details.accountNumber != 0)
			{
				printf("%-6d%-16s%-11s%10.2f%10.2f\n"
					, details.accountNumber
					, details.firstName
					, details.lastName
					, details.accountBalance
					, details.lastPaymentAmount);
			}

		}

		fclose(cfPtr); // fclose closes the file
	}

	_getch();
	return 0;
}