<?php	
	require 'bogosort.php';

	function Benchmark()
	{
		$start = floor(microtime(true) * 1000);
		bogosort(RandomArray($_GET['Len'], $_GET['Max']));
		$end = floor(microtime(true) * 1000);
		echo(($end - $start)/1000);
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
			<!-- <tr>
				<td><label for="Count">Count: </label></td>
				<td><input type="number" id="Count" value="1"></input></td>
			</tr> -->
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
		<!-- <p>Output: <span id="BenchmarkOutput">1, 2, 3</span></p> -->
	</form>
</body>