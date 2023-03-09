<?php
	Benchmark();

	function Bogosort($Arr)
	{
		while (!IsSorted($Arr))
		{
			$Arr = ShuffleArray($Arr);
		}
		return $Arr;
	}
	
	function IsSorted($Arr)
	{
		for($i = 0; $i < count($Arr) - 1; $i++)
		{
			if($Arr[$i] > $Arr[$i+1])
			{
				return False;
			}
		}
		return True;
	}
	
	function ShuffleArray($Arr)
	{
		for($i = 0; $i < count($Arr); $i++)
		{
			$OtherIndex = rand(0, count($Arr)-1);
			$Holder = $Arr[$i];
			$Arr[$i] = $Arr[$OtherIndex];
			$Arr[$OtherIndex] = $Holder;
		}
		return $Arr;
	}
	
	function RandomArray($Len, $Max)
	{
		$Arr = [];
		for($i = 0; $i < $Len; $i++)
		{
			array_push($Arr, rand(0, $Max));
		}
		return $Arr;
	}
?>
