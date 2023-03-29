using System;

public class Bogosort
{
	public static Random rand;

	static public void Main(string[] Args)
	{
		rand = new Random();
		
		int[] Arr = new int[0];
		bool Verbose = false;
		int Len = 8;
		int Max = 255;
		int Count = 1;
		
		for(int i = 0; i < Args.Length; i++)
		{
			switch(Args[i])
			{
				case "-l":
				{
					if(int.TryParse(Args[i+1], out Len))
					{
						i++;
					}
					else
					{
						Console.WriteLine("Invalid value for -l, \"" + Args[i+1] + "\"");
					}
					break;
				}
				case "-m":
				{
					if(int.TryParse(Args[i+1], out Max))
					{
						i++;
					}
					else
					{
						Console.WriteLine("Invalid value for -m, \"" + Args[i+1] + "\"");
					}
					break;
				}
				case "-c":
				{
					if(int.TryParse(Args[i+1], out Count))
					{
						i++;
					}
					else
					{
						Console.WriteLine("Invalid value for -c, \"" + Args[i+1] + "\"");
					}
					break;
				}
				case "-v":
				{
					Verbose = true;
					break;
				}
				case "-a":
					int j = i;
					while(i + j + 1 < Args.Length)
					{
						string s = Args[i+j+1];
						if(s.Substring(s.Length-1) == ",")
						{
							s = s.Substring(0, s.Length-1);
						}
						
						if(int.TryParse(s, out int a))
						{
							j++;
						}
						else
						{
							break;
						}
					}
					Arr = new int[j-i];
					for(j = 0; j < Arr.Length; j++)
					{						
						string s = Args[i+j+1];
						if(s.Substring(s.Length-1) == ",")
						{
							s = s.Substring(0, s.Length-1);
						}
						
						Arr[j] = int.Parse(s	);
					}
					i += j;
					break;
				default:
					Console.WriteLine("Unknown argument \"" + Args[i] + "\"");
					break;
			}
		}
		
		bool ArrSet = Arr.Length != 0;
		
		for(int Round = 0; Round < Count; Round++)
		{
			if(!ArrSet)
			{
				Arr = RandomArray(Len, Max);
			}
			
			bogosort(Arr);
		
			Console.Write(Arr[0]);
			for(int i = 1; i < Arr.Length; i++)
			{
				Console.Write(", " + Arr[i].ToString());
			}
			Console.WriteLine();
		}
	}
	
	public static int[] RandomArray(int Len, int Max)
	{
		int[] Arr = new int[Len];
		for(int i = 0; i < Len; i++)
		{
			Arr[i] = rand.Next() % Max + 1;
		}
		return Arr;
	}
	
	public static void bogosort(int[] Arr)
	{
		while(!IsSorted(Arr))
		{
			Randomize(Arr);
		}	
	}
	
	public static bool IsSorted(int[] Arr)
	{
		for(int i = 0; i < Arr.Length - 1; i++)
		{
			if(Arr[i] > Arr[i+1])
			{
				return false;
			}
		}
		return true;
	}
	
	public static void Randomize(int[] Arr)
	{
		for(int i = 0; i < Arr.Length; i++)
		{
			int OtherIndex = rand.Next() % Arr.Length;
			int Holder = Arr[i];
			Arr[i] = Arr[OtherIndex];
			Arr[OtherIndex] = Holder;
		}
	}
}
