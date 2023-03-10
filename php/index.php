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
