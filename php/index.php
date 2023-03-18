<?php	
	require 'bogosort.php';

	$BenchmarkOutput = "Run the benchmark first!";
	
	Benchmark();

	function Benchmark()
	{
		global $BenchmarkOutput;
		$BenchmarkOutput = "<br>";
		
		$Verbose = isset($_GET['Verbose']);
		$IndividualTimes = [];
		
		$Start = floor(microtime(true) * 1000);
		for($i = 0; $i < $_GET['Count']; $i++)
		{
			if($Verbose)
			{
				$IndividualStart = floor(microtime(true) * 1000);
			}
			bogosort(RandomArray($_GET['Len'], $_GET['Max']));
			if($Verbose)
			{
				array_push($IndividualTimes, floor((microtime(true) * 1000)- $IndividualStart)/1000);
			}
		}

		$SummedUpTime = 0;
		for($i = 0; $i < count($IndividualTimes); $i++)
		{
			$BenchmarkOutput .= $i .": " .$IndividualTimes[$i] ."s<br>";
			$SummedUpTime += $IndividualTimes[$i];
		}
		$BenchmarkOutput .= "Average time: " .($SummedUpTime / count($IndividualTimes)) ."s<br>";
		$BenchmarkOutput .= "Summed up time: " .$SummedUpTime ."s<br>";

		$End = floor(microtime(true) * 1000);
		$BenchmarkOutput .= "Total: " .(($End - $Start)/1000) ."s";
	}
?>

<!DOCTYPE html>
<head>
</head>
<body>
	<!--<h2>Bogosort!</h2>
	<label for="Arr">Comma seperated starting list: </label>
	<input type="text" id="Arr"></input></br>
	<button onClick="document.getElementById('Output').innerHTML = Bogosort(ParseInput());">Sort</button>
	<p>Output: <span id="Output">1, 2, 3</span></p>
	<br> -->
	<h2>Benchmark</h2>
	<form action="#" method="GET">
		<table>
			<tr>
				<th>Field</th>
				<th>Value</th>
			</tr>
			<tr>
				<td><label for="Count">Count: </label></td>
				<td><input type="number" name="Count" id="Count" value="<?php if(isset($_GET['Count'])) { echo($_GET['Count']); } else {echo("1"); } ?>"></input></td>
			</tr> 
			<tr>
				<td><label for="Len">Length: </label></td>
				<td><input type="number" name="Len" id="Len" value="<?php if(isset($_GET['Len'])) { echo($_GET['Len']); } else {echo("8"); } ?>"></input></td>
			</tr>
			<tr>
				<td><label for="Max">Max Number: </label></td>
				<td><input type="number" name="Max" id="Max" value="<?php if(isset($_GET['Max'])) { echo($_GET['Max']); } else {echo("255"); } ?>"></input></td>
			</tr>
			<tr>
				<td><label for="Verbose">Verbose: </label></td>
				<td><input type="checkbox" name="Verbose" id="Verbose" <?php if(isset($_GET['Verbose'])) { echo("checked"); } ?>></input></td>
			</tr>
		</table>
		<br>
		<input type="submit"></submit>
		<p>Output: <span id="BenchmarkOutput"><?php echo($BenchmarkOutput); ?></span></p>
	</form>
</body>
