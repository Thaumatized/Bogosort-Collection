#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

void bogosort();
void shuffle();
int issorted();
void RandomArray();

void bogosort(int Arr[], int Len)
{
	while(issorted(Arr, Len) == 0)
	{
		shuffle(Arr, Len);
	}
}

void shuffle(int Arr[], int Len)
{
	for(int i = 0; i < Len; i++)
	{
		int OtherIndex = rand() % Len;
		int Holder = Arr[OtherIndex];
		Arr[OtherIndex] = Arr[i];
		Arr[i] = Holder;
	}
}

int issorted(int Arr[], int Len)
{
	for(int i = 0; i < Len-1; i++)
	{
		if(Arr[i] > Arr[i+1]) return 0;
	}
	return 1;
}

void RandomArray(int Arr[], int Len, int Max)
{
	for (int i = 0; i < Len; i++)
	{
		Arr[i] = rand() % (Max + 1);
	}
}

int main(int argc, char *argv[])
{
	//Rand init
	time_t t = time(NULL);
	srand(t);
	
	int Len = 5;
	int Max = 255;
	bool Verbose = false;
	bool ArrSet = false;

	for (int i = 1; i < argc; i++)
	{
		printf("%s", argv[i]);
		printf("\n");
		if (!strcmp(argv[i], "-c"))
		{
			Len = atoi(argv[i+1]);
			i++;
		}
		if (!strcmp(argv[i], "-m"))
		{
			Max = atoi(argv[i+1]);
			i++;
		}
	}
	printf("%i", Max);
	printf("\n");
	
	int Arr[Len];

	if(!ArrSet)
	{
		RandomArray(Arr, Len, Max);
	}
	
	for(int i = 0; i < Len; i++)
	{
		if(i) printf(", ");
		printf("%i", Arr[i]);
	}
	printf("\n");
	
	bogosort(Arr, Len);
	
	for(int i = 0; i < Len; i++)
	{
		if(i) printf(", ");
		printf("%i", Arr[i]);
	}
	printf("\n");
	
	return 0;
}

