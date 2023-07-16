function Bogosort(Arr)
{
	while(!IsSorted(Arr))
	{
		Shuffle(Arr);
	}
	return Arr;
};

function Shuffle(Arr){
	for(let i = 0; i < Arr.length; i++)
	{
		let OtherIndex = Math.floor(Math.random() * Arr.length);
		let Holder = Arr[i];
		Arr[i] = Arr[OtherIndex];
		Arr[OtherIndex] = Holder;
	}
	return Arr;
};

function IsSorted(Arr){
	for(let i = 0; i < Arr.length - 1; i++)
	{
		if(Arr[i] > Arr[i+1])
		{
			return false;
		}
	}
	return true;
};

function RandomArray(Len = 5, Max = 255){
	let Arr = [];
	for(let i = 0; i < Len; i++)
	{
		Arr.push(Math.floor(Math.random() * Max + 1));
	}
	return Arr;
};

let Verbose = false;
let Len = 8;
let Max = 255;
let Count = 1;
let Arr = [];

for(i = 1; i < process.argv.length; i++)
{
	switch(process.argv[i])
	{
		case "-v":
			Verbose = true;
			break;
		case "-l":
			i++;
			Len = Number(process.argv[i]);
			break; 
		case "-m":
			i++;
			Max = Number(process.argv[i]);
			break; 
		case "-c":
			i++;
			Count = Number(process.argv[i]);
			break;
		case "-a":
			let Var = "0";
			while(!isNaN(Var) && i < process.argv.length - 1)
			{
				Var = process.argv[i+1].replace(",", "");
				Arr.push(Number(Var));
				i++;
			}
			break;
	}
}

if(Arr.length > 0)
{
	Arr = Bogosort(Arr);
	let First = true;
	let Result = "";
	Arr.forEach(element => {
		if(!First)
		{
			Result += ", ";
		}
		else
		{
			First = false;
		}
		Result += element;
	});
	console.log(Result);
}
else
{
	let IndividualTimes = [];

	let Start = new Date().getTime();

	let IndividualStart = 0;

	for(i = 0; i < Count; i++)
	{
		if(Verbose)
		{
			IndividualStart = new Date().getTime();
		}
		Bogosort(RandomArray(Len, Max));
		if(Verbose)
		{
			IndividualTimes.push((new Date().getTime() - IndividualStart) / 1000);
			console.log( i + ": " + IndividualTimes[i] + "s");
		}
	}

	if(Verbose)
	{
		let SummedUpTime = 0;
		for(i = 0; i < IndividualTimes.length; i++)
		{
			SummedUpTime += IndividualTimes[i];
		}
		console.log("Average time: " + (SummedUpTime / IndividualTimes.length) + "s");
		console.log("Summed up time: " + SummedUpTime + "s");
	}

	let End = new Date().getTime();
	console.log("Total: " + ((End - Start)/1000) + "s");
}