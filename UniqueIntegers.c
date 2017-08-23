//Author: Jason Chan A00698160
//This program is to accept 20 int inputs and 
//displays all unique numbers using array

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main(){
	int array[20];
	int size = 20;
	int i;
	int number;
	const int MIN_VALUE = 10;
	const int MAX_VALUE = 100;

	for (i = 0; i < size; i++)
	{
		printf("\nEnter # %d : ", i+1);
		scanf("%d", &number);

		if (number < MIN_VALUE || number > MAX_VALUE){
			printf("%s%d%s%d%s",
				"The number enetered is not in the valid range of "
				, MIN_VALUE, " to ", MAX_VALUE, "\n");
			i--;
			continue;
		}
	}

	_getch();
	return 0;
}