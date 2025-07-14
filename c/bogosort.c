#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

void bogosort();
void shuffle();
int isSorted();
void randomArray();
void printArray();

void bogosort(int* arr, int len)
{
	while(isSorted(arr, len) == 0)
	{
		shuffle(arr, len);
	}
}

void shuffle(int* arr, int len)
{
	for(int i = 0; i < len; i++)
	{
		int otherIndex = rand() % len;
		int holder = arr[otherIndex];
		arr[otherIndex] = arr[i];
		arr[i] = holder;
	}
}

int isSorted(int* arr, int len)
{
	for(int i = 0; i < len-1; i++)
	{
		if(arr[i] > arr[i+1]) return 0;
	}
	return 1;
}

void randomArray(int* arr, int len, int max)
{
	for (int i = 0; i < len; i++)
	{
		arr[i] = rand() % (max + 1);
	}
}

void printArray(int* arr, int len)
{
	for(int i = 0; i < len; i++)
	{
		if(i) printf(", ");
		printf("%i", arr[i]);
	}
}

int main(int argc, char *argv[])
{
	//Rand init
	time_t t = time(NULL);
	srand(t);
	
	int len = 8;
	int max = 255;
	int count = 1;
	bool verbose = false;
	int arrArgIndex = 0;
	
	int* arr;

	for (int i = 1; i < argc; i++)
	{
		if (!strcmp(argv[i], "-l"))
		{
			if(!arrArgIndex)
			{
				len = atoi(argv[i+1]);
			}
			i++;
		}
		if (!strcmp(argv[i], "-m"))
		{
			max = atoi(argv[i+1]);
			i++;
		}
		if (!strcmp(argv[i], "-c"))
		{
			count = atoi(argv[i+1]);
			i++;
		}
		if (!strcmp(argv[i], "-v"))
		{
			verbose = true;
		}
		if (!strcmp(argv[i], "-a"))
		{
			//i2 = argument index to insert into the array
			int i2 = i+1;
			while((i2 < argc) && (atoi(argv[i2]) || !strcmp("0", argv[i2])))
			{
				i2++;
			}
			len = i2 - i - 1;
			if(len > 0) arrArgIndex = i + 1;
			i = i2 - 1;
		}
	}

	int temparr[len];
	arr = temparr;
	float individualTimes[count];
	if(arrArgIndex)
	{
		for (int i = 0; i < len; i++)
		{
			arr[i] = atoi(argv[arrArgIndex+i]);
		}

		bogosort(arr, len);
		
		printArray(arr, len);
	}
	else
	{
		clock_t overallStartClock, overallStopClock;
		
		overallStartClock = clock();
		
		for(int i = 0; i < count; i++)
		{
			clock_t individualStartClock, individualStopClock;
			individualStartClock = clock();
			
			randomArray(arr, len, max);
			
			bogosort(arr, len);
			
			
			if(verbose)
			{
				individualStopClock = clock();
				printf("\n%i: %6.3f", i, (double)(individualStopClock - individualStartClock) / CLOCKS_PER_SEC);
				individualTimes[i] = (double)(individualStopClock - individualStartClock) / CLOCKS_PER_SEC;
			}
		}
		
		overallStopClock = clock();
		
		float average, sum = 0;
		
		for(int i = 0; i < count; i++)
		{
			sum += individualTimes[i];
		}
		average = sum / count;
		
		if(verbose)
		{
			printf("\naverage time: %6.3f\n", average);
			printf("\nsummed up time: %6.3f\n", sum);
		}
		printf("\ntotal time: %6.3f\n", (double)(overallStopClock - overallStartClock) / CLOCKS_PER_SEC);
	}
	
	return 0;
}
