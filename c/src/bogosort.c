#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int bogosort();
int shuffle();
int issorted();

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

int main()
{
	//Rand init
	time_t t = time(NULL);
	srand(t);
	
	int Len = 5;
	int Max = 255;
	
	int Arr[5] = {0, 7, 4, 21, 9};
	
	for(int i = 0; i < Len; i++){printf("%i", Arr[i]); printf(", ");}
	printf("\n");
	
	bogosort(Arr, Len);
	
	for(int i = 0; i < Len; i++){printf("%i", Arr[i]); printf(", ");}
	printf("\n");
	
	return 0;
}

