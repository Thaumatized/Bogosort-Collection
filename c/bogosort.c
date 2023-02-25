#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

void bogosort();
void shuffle();
int issorted();
void RandomArray();
void PrintArray();

void bogosort(int* Arr, int Len)
{
	while(issorted(Arr, Len) == 0)
	{
		shuffle(Arr, Len);
	}
}

void shuffle(int* Arr, int Len)
{
	for(int i = 0; i < Len; i++)
	{
		int OtherIndex = rand() % Len;
		int Holder = Arr[OtherIndex];
		Arr[OtherIndex] = Arr[i];
		Arr[i] = Holder;
	}
}

int issorted(int* Arr, int Len)
{
	for(int i = 0; i < Len-1; i++)
	{
		if(Arr[i] > Arr[i+1]) return 0;
	}
	return 1;
}

void RandomArray(int* Arr, int Len, int Max)
{
	for (int i = 0; i < Len; i++)
	{
		Arr[i] = rand() % (Max + 1);
	}
}

void PrintArray(int* Arr, int Len)
{
	for(int i = 0; i < Len; i++)
	{
		if(i) printf(", ");
		printf("%i", Arr[i]);
	}
	printf("\n");
}

int main(int argc, char *argv[])
{
	//Rand init
	time_t t = time(NULL);
	srand(t);
	
	int Len = 10;
	int Max = 255;
	int Count = 1;
	bool Verbose = false;
	int ArrArgIndex = 0;
	
	int* Arr;

	for (int i = 1; i < argc; i++)
	{
		if (!strcmp(argv[i], "-l"))
		{
			if(!ArrArgIndex)
			{
				Len = atoi(argv[i+1]);
			}
			i++;
		}
		if (!strcmp(argv[i], "-m"))
		{
			Max = atoi(argv[i+1]);
			i++;
		}
		if (!strcmp(argv[i], "-c"))
		{
			Count = atoi(argv[i+1]);
			i++;
		}
		if (!strcmp(argv[i], "-v"))
		{
			Verbose = true;
		}
		if (!strcmp(argv[i], "-a"))
		{
			//i2 = argument index to insert into the array
			int i2 = i+1;
			while((i2 < argc) && (atoi(argv[i2]) || !strcmp("0", argv[i2])))
			{
				i2++;
			}
			Len = i2 - i - 1;
			if(Len > 0) ArrArgIndex = i + 1;
		}
	}

	int temparr[Len];
	Arr = temparr;
	float IndividualTimes[Count];
	if(ArrArgIndex)
	{
		for (int i = 0; i < Len; i++)
		{
			Arr[i] = atoi(argv[ArrArgIndex+i]);
		}
		
		PrintArray(Arr, Len);
		
		bogosort(Arr, Len);
		
		PrintArray(Arr, Len);
	}
	else
	{
		clock_t Start, Stop;
		
		Start = clock();
		
		for(int i = 0; i < Count; i++)
		{
			clock_t Start2, Stop2;
			Start2 = clock();
			
			RandomArray(Arr, Len, Max);
			
			bogosort(Arr, Len);
			
			
			if(Verbose)
			{
				Stop2 = clock();
				printf("\n%i: %6.3f", i, (double)(Stop2 - Start2) / CLOCKS_PER_SEC);
				IndividualTimes[i] = (double)(Stop2 - Start2) / CLOCKS_PER_SEC;
			}
		}
		
		Stop = clock();
		
		float average, sum = 0;
		
		for(int i = 0; i < Count; i++)
		{
			sum += IndividualTimes[i];
		}
		average = sum / Count;
		
		printf("\naverage time: %6.3f\n", average);
		printf("\nsummed up time: %6.3f\n", sum);
		printf("\ntotal time: %6.3f\n", (double)(Stop - Start) / CLOCKS_PER_SEC);
	}
	
	return 0;
}