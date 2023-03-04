<?php
	echo("a");
	$Arr = Bogosort([1, 2, 3, 0]);

	function Bogosort($Arr)
	{
		while !IsSorted($Arr)
		{
			Shuffle($Arr);
		}
		return $Arr;
	}
	
	IsSorted($Arr)
	{
		for($i =0; $i < length($Arr) - 1; $i++)
		{
			if($Arr[i] > $Arr[i+1])
			{
				return False;
			}
		}
		return True;
	}
	
	Shuffle($Arr)
	{
		for($i =0; $i < length($Arr); $i++)
		{
			if($Arr[i] > $Arr[i+1])
			{
				return False;
			}
		}
	}
?>
