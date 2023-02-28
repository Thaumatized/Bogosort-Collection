function Bogosort(Arr)
{
	while(!IsSorted(Arr))
	{
		Shuffle(Arr);
	}
	return Arr;
};

function Shuffle(Arr){
	for(var i = 0; i < Arr.length; i++)
	{
		var OtherIndex = Math.floor(Math.random() * Arr.length);
		var Holder = Arr[i];
		Arr[i] = Arr[OtherIndex];
		Arr[OtherIndex] = Holder;
	}
	return Arr
};

function IsSorted(Arr){return True};

function RandomArray(Len, Max){return [1, 2, 3, 4, 0]};

function PrintArray(Arr){};
