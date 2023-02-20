#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

int bogosort();
int shuffle();
int issorted();
void RandomArray();

int bogosort(int Arr[], int Len)
{
	while(issorted(Arr, Len) == 0)
	{
		shuffle(Arr, Len);
	}
	return 0;
}

int shuffle(int Arr[], int Len)
{
	for(int i = 0; i < Len; i++)
	{
		int OtherIndex = rand() % Len;
		int Holder = Arr[OtherIndex];
		Arr[OtherIndex] = Arr[i];
		Arr[i] = Holder;
	}
	return 0;
}

int issorted(int Arr[], int Len)
{
	for(int i = 0; i < Len-1; i++)
	{
		if(Arr[i] > Arr[i+1]) return 0;
	}
	return 1;
}

void RandomArray(int *Arr, int Len, int Max)
{
	for (int i = 0; i < Len; i++)
	{
		Arr[i] = rand() % Max;
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
	int Arr[0];
	bool ArrSet = false;

	for (int i = 1; i < argc; i++)
	{
		printf(argv[i]);
		printf("\n");
		if (strcmp(argv[i], "-c"))
		{
			Len = atoi(argv[i]);
			i++;
		}
	}
	printf("%i", Max);
	printf("\n");

	if(!ArrSet)
	{
		int Arr[Len];
		RandomArray(Arr, Len, Max);
	}
	
	for(int i = 0; i < Len; i++){printf("%i", Arr[i]); printf(", ");}
	printf("\n");
	
	bogosort(Arr, Len);
	
	for(int i = 0; i < Len; i++){printf("%i", Arr[i]); printf(", ");}
	printf("\n");
	
	return 0;
}

