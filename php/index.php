<?php	
	require 'bogosort.php';

	function Benchmark()
	{
		$start = floor(microtime(true) * 1000);
		bogosort(RandomArray(10, 255));
		$end = floor(microtime(true) * 1000);
		echo(($end - $start)/1000);
	}
?>
