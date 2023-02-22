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
		int Holder = *(Arr + OtherIndex);
		*(Arr + OtherIndex) = *(Arr + i);
		*(Arr + i) = Holder;
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
	int temparr[Len];
	Arr = &temparr[0];
	for (int i = 0; i < Len; i++)
	{
		*(Arr + i) = rand() % (Max + 1);
	}
}

void PrintArray(int* Arr, int Len)
{
	for(int i = 0; i < Len; i++)
	{
		if(i) printf(", ");
		printf("%i", *(Arr + i));
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
	bool ArrSet = false;
	
	int* Arr;

	for (int i = 1; i < argc; i++)
	{
		if (!strcmp(argv[i], "-l"))
		{
			Len = atoi(argv[i+1]);
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
			int i2 = i+1;
			printf("\n");
			while((i2 < argc) && (atoi(argv[i2]) || !strcmp("0", argv[i2])))
			{
				printf("%s", argv[i2]);
				i2++;
			}
			Len = i2 - i - 1;
			int TempArr[Len];
			Arr = &(TempArr[0]);
			i2 = i+1;
			int i3 = 0;
			while(i2 < argc && (atoi(argv[i2]) || !strcmp("0", argv[i2])))
			{
				*(Arr + i3) = atoi(argv[i2]);
				i2++;
				i3++;
			}
			ArrSet = true;
		}
	}

	if(!ArrSet)
	{
		RandomArray(Arr, Len, Max);
	}
	
	PrintArray(Arr, Len);
	/*
	
	bogosort(Arr, Len);
	
	PrintArray(Arr, Len);
	*/
	
	return 0;
}

