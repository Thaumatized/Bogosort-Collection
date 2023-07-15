<?php
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

	$Verbose = false;
	$Len = 8;
	$Max = 255;
	$Count = 1;
	$Arr = [];

	for($i = 1; $i < $argc; $i++)
	{
		switch($argv[$i])
		{
			case "-v":
				$Verbose = true;
				break;
			case "-l":
				$i++;
				$Len = intval($argv[$i]);
				break; 
			case "-m":
				$i++;
				$Max = intval($argv[$i]);
				break; 
			case "-c":
				$i++;
				$Count = intval($argv[$i]);
				break;
			case "-a":
				$Var = "0";
				while(is_numeric($Var) && $i < $argc - 1)
				{
					$Var = str_replace(",", "", $argv[$i+1]);
					array_push($Arr, intval($Var));
					$i++;
				}
				break;
		}
	}

	if($Arr != [])
	{
		$Arr = Bogosort($Arr);
		$First = True;
		foreach($Arr as $Num)
		{
			if(!$First)
			{
				echo ", ";
			}
			else
			{
				$First = False;
			}
			echo $Num;
		}
		echo "\n";
	}
	else
	{
		$IndividualTimes = [];
	
		$Start = floor(microtime(true) * 1000);
	
		for($i = 0; $i < $Count; $i++)
		{
			if($Verbose)
			{
				$IndividualStart = floor(microtime(true) * 1000);
			}
			bogosort(RandomArray($Len, $Max));
			if($Verbose)
			{
				array_push($IndividualTimes, floor((microtime(true) * 1000)- $IndividualStart)/1000);
			}
		}
	
		if($Verbose)
		{
			$SummedUpTime = 0;
			for($i = 0; $i < count($IndividualTimes); $i++)
			{
				echo $i .": " .$IndividualTimes[$i] ."s\n";
				$SummedUpTime += $IndividualTimes[$i];
			}
			echo "Average time: " .($SummedUpTime / count($IndividualTimes)) ."s\n";
			echo "Summed up time: " .$SummedUpTime ."s\n";
		}
	
		$End = floor(microtime(true) * 1000);
		echo "Total: " .(($End - $Start)/1000) ."s\n";
	}
?>
