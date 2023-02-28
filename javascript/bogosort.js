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
	return Arr;
};

function IsSorted(Arr){
	for(var i = 0; i < Arr.length - 1; i++)
	{
		if(Arr[i] > Arr[i+1])
		{
			return false;
		}
	}
	return true;
};

function RandomArray(Len = 5, Max = 255){
	var Arr = [];
	for(var i = 0; i < Len; i++)
	{
		Arr.push(Math.floor(Math.random() * Max + 1));
	}
	return Arr;
};
