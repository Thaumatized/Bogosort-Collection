use rand::{rngs::ThreadRng, Rng};

fn bogosort(arr: &mut Vec<i32>)
{
	while !is_sorted(arr)
	{
		shuffle(arr);
	}
}

fn shuffle(arr: &mut Vec<i32>)
{
    let mut rng: ThreadRng = rand::rng();

	for i in 0..arr.len()
	{
		let other_index = (rng.random::<u32>() % arr.len() as u32) as usize;
		let holder = arr[other_index];
		arr[other_index] = arr[i];
		arr[i] = holder;
	}
}

fn is_sorted(arr: &Vec<i32>) -> bool
{
	for i in 0..arr.len()-1
	{
		if arr[i] > arr[i+1] {
            return false;
        }
	}
	return true;
}

fn random_array(len: usize, max: i32) -> Vec<i32>
{
    let mut rng: ThreadRng = rand::rng();

	let mut arr: Vec<i32> = vec![];
	for i in 0..len
	{
		arr.insert(i, rng.random::<i32>() % max+1);
	}
	arr
}

fn print_array(arr: &Vec<i32>)
{
	for i in 0..arr.len()
	{
		if i != 0
		{
			print!(", ");
		}
		print!("{}", arr[i]);
	}
}

fn main() {
    let args: Vec<String> = std::env::args().collect();

	let mut len: usize = 8;
	let mut max: i32 = 255;
	let mut count: usize = 1;
	let mut verbose: bool = false;
	
	let mut arr: Vec<i32> = vec![];

	let mut i = 0;
	while i < args.len()
	{
		if &args[i] == "-l"
		{
			if arr.len() == 0
			{
				len = args[i+1].parse::<usize>().unwrap();
			}
			i += 1;
		}
		if &args[i] == "-m"
		{
			max = args[i+1].parse::<i32>().unwrap();
			i += 1;
		}
		if &args[i] == "-c"
		{
			count = args[i+1].parse::<usize>().unwrap();
			i += 1;
		}
		if &args[i] == "-v"
		{
			verbose = true;
		}
		if &args[i] == "-a"
		{
			//i2 = argument index to insert into the array
			let mut i2 = i+1;
			while i2 < args.len() && !args[i2].parse::<i32>().is_err()
			{
				arr.insert(i2 - i - 1, args[i2].parse::<i32>().unwrap());
				i2 += 1;
			}
		}

		i += 1;
	}

	if arr.len() > 0
	{
		bogosort(&mut arr);
		print_array(&arr);
	}
	else
	{
		let mut individual_times: Vec<f32> = vec![];


		let overall_clock = std::time::Instant::now();
		
		for i in 0..count
		{
			let individual_clock = std::time::Instant::now();
			
			let mut arr = random_array(len, max);
			
			bogosort(&mut arr);
			
			
			if verbose
			{
				let individual_time = individual_clock.elapsed().as_secs_f32();
				println!("{}: {:.3}", i, individual_time);
				individual_times.insert(i, individual_time);
			}
		}
		
		let overall_time = overall_clock.elapsed().as_secs_f32();
		
		let mut sum = 0.0;
		
		for time in individual_times
		{
			sum += time;
		}

		let average = sum / count as f32;
		
		if verbose
		{
			println!("average time: {:.3}", average);
			println!("");
			println!("summed up time: {:.3}", sum);
			println!("");
		}
		println!("total time: {:.3}\n", overall_time);
	}
}