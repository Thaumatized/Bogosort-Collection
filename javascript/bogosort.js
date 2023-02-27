function Bogosort(Arr)
{
	while(!IsSorted(Arr))
	{
		Shuffle(Arr);
	}
	return Arr;
};

function Shuffle(Arr){return Arr};

function IsSorted(Arr){return True};

function RandomArray(Len, Max){return [1, 2, 3, 4, 0]};

function PrintArray(Arr){};
