package bogosort;

import java.util.Random;

public class Bogosort
{
	public static Random rand;

	static public void main(String[] Args)
	{
		rand = new Random();
		
		int[] Arr = new int[0];
		boolean Verbose = false;
		int Len = 8;
		int Max = 255;
		int Count = 1;
		
		for(int i = 0; i < Args.length; i++)
		{
			switch(Args[i])
			{
				case "-l":
					try
					{
						Len = Integer.parseInt(Args[i+1]);
						i++;
					}
					catch(Error e)
					{
						System.out.println("Invalid value for -l, \"" + Args[i+1] + "\"");
					}
					break;
				case "-m":
					try
					{
						Max = Integer.parseInt(Args[i+1]);
						i++;
					}
					catch(Error e)
					{
						System.out.println("Invalid value for -m, \"" + Args[i+1] + "\"");
					}
					break;
				case "-c":
					try
					{
						Count = Integer.parseInt(Args[i+1]);
						i++;
					}
					catch(Error e)
					{
						System.out.println("Invalid value for -c, \"" + Args[i+1] + "\"");
					}
					break;
				case "-v":
					Verbose = true;
					break;
				case "-a":
					int j = 1;
					while(i + j < Args.length)
					{
						String s = Args[i+j];
						if(s.endsWith(","))
						{
							s = s.substring(0, s.length()-1);
						}

						try
						{
							Integer.parseInt(s);
							j++;
						}
						catch(Error e)
						{
							break;
						}
					}
					Arr = new int[j-1];
					for(j = 0; j < Arr.length; j++)
					{						
						String s = Args[i+j+1];
						if(s.endsWith(","))
						{
							s = s.substring(0, s.length()-1);
						}
						
						Arr[j] = Integer.parseInt(s);
					}
					i += j;
					break;
				default:
					System.out.println("Unknown argument \"" + Args[i] + "\"");
					break;
			}
		}
		
		if(Arr.length != 0)
		{
				bogosort(Arr);
			
				System.out.print(Arr[0]);
				for(int i = 1; i < Arr.length; i++)
				{
					System.out.print(", " + Integer.toString(Arr[i]));
				}
				System.out.println();
		}
		else
		{
			float[] IndividualTimes = new float[Count];
			
			long StartTime = System.nanoTime();
			long IndividualStartTime = 0;
			
			for(int Round = 0; Round < Count; Round++)
			{
				if(Verbose)
				{
					IndividualStartTime = System.nanoTime();
				}
				
				Arr = RandomArray(Len, Max);
				
				bogosort(Arr);
				
				if(Verbose)
				{
					IndividualTimes[Round] = ((float)(System.nanoTime() - IndividualStartTime))/1000000000;
					System.out.printf("%d: %.3f\n", Round, IndividualTimes[Round]);
				}
			}
			
			long TotalTime = System.nanoTime() - StartTime;
			
			if(Verbose)
			{
				float SummedUpTime = 0;
				for(int i = 0; i < Count; i++)
				{
					SummedUpTime += IndividualTimes[i];
				}
				float AverageTime = (SummedUpTime/Count);
				
				System.out.printf("Average time: %.3f\n", AverageTime);
				System.out.printf("Summed up time: %.3f\n", SummedUpTime);
			}
			
			System.out.printf("Total time: %.3f\n", (float)TotalTime/1000000000);
		}
	}
	
	public static int[] RandomArray(int Len, int Max)
	{
		int[] Arr = new int[Len];
		for(int i = 0; i < Len; i++)
		{
			Arr[i] =  Math.abs(rand.nextInt()) % Max + 1;
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
	
	public static boolean IsSorted(int[] Arr)
	{
		for(int i = 0; i < Arr.length - 1; i++)
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
		for(int i = 0; i < Arr.length; i++)
		{
			int OtherIndex = Math.abs(rand.nextInt() % Arr.length);
			int Holder = Arr[i];
			Arr[i] = Arr[OtherIndex];
			Arr[OtherIndex] = Holder;
		}
	}
}