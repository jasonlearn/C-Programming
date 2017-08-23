// Author: Jason Chan

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include <stdlib.h>
#include <time.h>

int main( int argc, char *argv[] )
{
	int elementCount;
	int *arrayBase;
	int counter;
	int elementValue;
	int currentSize;
	int previousSize;
	
	if (argc != 3)
	{
		printf("USAGE: program 2 9\n");
		return 1;
	}

	if (!sscanf(argv[1], "%d", &currentSize))
	{
		printf("Arguments must be numeric (int)\n");
		return 1;
	}

	if (!sscanf(argv[2], "%d", &elementCount))
	{
		printf("Arguments must be numeric (int)\n");
		return 1;
	}

	if (currentSize < 1)
	{
		printf("Initial size must be at least 1\n");
		return 1;
	}

	srand((int) time(NULL));
	
	arrayBase = (int*)calloc(currentSize, sizeof(int));
	
	printf("Initial array size: %d\n", currentSize);
	printf("Adding: %d %s\n", elementCount, elementCount == 1 ? "element" : "elements");

	elementValue = rand();
	elementValue %= 99;
	printf("Adding value: %2d Element Count: %2d\n", elementValue, 1);
	arrayBase[0] = elementValue;

	for (counter = 1; counter < elementCount; counter++)
	{
		if (counter == currentSize)
		{
			previousSize = currentSize;
			currentSize *= 2;
			printf("Increasing array size: from %d elements to %d elements\n", previousSize, currentSize);
			arrayBase = (int*)realloc(arrayBase, currentSize * sizeof(int));
		}

		elementValue = rand();
		elementValue %= 99;
		printf("Adding value: %2d Element Count: %2d\n", elementValue, counter + 1);
		arrayBase[counter] = elementValue;
	}

	// output section
	if (elementCount > 0)
	{
		printf("%s %d", elementCount == 1 ? "\nValue added is:" : "\nValues added are:" , arrayBase[0]);
	}
	else
	{
		printf("No array elements added");
	}

	if (elementCount > 1)
	{ 
		for (counter = 1; counter < elementCount; counter++)
		{
			printf(", %d", arrayBase[counter]);
		}
	}

	printf("\n\n");

	free(arrayBase);

	return 0;
}


