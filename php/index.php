<?php	
	require 'bogosort.php';

	$BenchmarkOutput = "Run the benchmark first!";
	
	Benchmark();

	function Benchmark()
	{
		global $BenchmarkOutput;
		
		$start = floor(microtime(true) * 1000);
		for($i = 0; $i < $_GET['Count']; $i++)
		{
			bogosort(RandomArray($_GET['Len'], $_GET['Max']));
			$end = floor(microtime(true) * 1000);
		}
		$BenchmarkOutput = (($end - $start)/1000) ."s";
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
				<td><input type="number" name="Count" id="Count" value="1"></input></td>
			</tr> 
			<tr>
				<td><label for="Len">Length: </label></td>
				<td><input type="number" name="Len" id="Len" value="8"></input></td>
			</tr>
			<tr>
				<td><label for="Max">Max Number: </label></td>
				<td><input type="number" name="Max" id="Max" value="255"></input></td>
			</tr>
			<!-- <tr>
				<td><label for="Verbose">Verbose: </label></td>
				<td><input type="checkbox" id="Verbose"></input></td>
			</tr> -->
		</table>
		<br>
		<input type="submit"></submit>
		<p>Output: <span id="BenchmarkOutput"><?php echo($BenchmarkOutput) ?></span></p>
	</form>
</body>
