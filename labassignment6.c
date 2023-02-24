#include <stdio.h>
#include <stdlib.h>

//using binary search to find value
int search(int numbers[], int low, int high, int value) 
{
    int mid; //intialize value

    if(high<low) //means if the value does not exist
        return -1;
    
    mid = (low+high)/2; //trying to find the middle value

    if(value>numbers[mid]) //have to search higher in the array
        return search(numbers,low+1, high, value);
    else if(value<numbers[mid]) //have to search lower in the array
        return search(numbers,low, high-1, value);
    else //it was the middle value
        return mid;
} 

void printArray(int numbers[], int sz)
{
	int i;
	printf("Number array : ");
	for (i = 0;i<sz;++i)
	{
		printf("%d ",numbers[i]);
	}
	printf("\n");
}

int main(void)
{
	int i, numInputs;
	char* str;
	float average;
	int value;
	int index;
	int* numArray = NULL;
	int countOfNums;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &countOfNums);
		numArray = (int *) malloc(countOfNums * sizeof(int));
		average = 0;
		for (i = 0; i < countOfNums; i++)
		{
			fscanf(inFile," %d", &value);
			numArray[i] = value;
			average += numArray[i];
		}

		printArray(numArray, countOfNums);
		value = average / countOfNums;
		index = search(numArray, 0, countOfNums - 1, value);
		if (index >= 0)
		{
			printf("Item %d exists in the number array at index %d!\n",value, index);
		}
		else
		{
			printf("Item %d does not exist in the number array!\n", value);
		}

		free(numArray);
	}

	fclose(inFile);

    return 0;
}
