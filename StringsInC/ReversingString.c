//Displaying a sentence with its words reversed
//Authur: Jason Chan

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

void reversTokens(char *sentence);

//initialize array string
char sentence[SIZE];
char *arrayPtr[SIZE] = { 0 };
int index = 0; //index for loop
int shift = 2;

int main(void){

	//prompts for user input
	puts("Enter a line of text:");
	fgets(sentence, SIZE, stdin);

	//displays reversed sentence
	puts("\nThe tokens in reversed order are:");
	reversTokens(sentence);
	puts("\n");

	_getch();
	return 0;
}

//reverseTokens function
void reversTokens(char *sentence){

	//create seperators pointer to char
	char * seperators = " ,;-?!.\n"; 

	arrayPtr[index++] = strtok(sentence, " ,;-?!.\n"); //begin tokenizing sentence

	//continues to tokenize sentence until arrayPtr equals null
	while (arrayPtr[ index - 1 ] != NULL)
	{
		arrayPtr[index++] = strtok(NULL, seperators);
	}

	//to shift index
	index -= shift; 

	//displays the sentence 
	for (; index >= 0; index--)
	{
		printf("%s  ", arrayPtr[index]);
	}
}//end reverseTokens function