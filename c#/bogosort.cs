using System;

public class Bogosort
{
	public static Random rand;

	static public void Main()
	{
		rand = new Random();
		int[] Arr = new int[]{1, 2, 3, 4, 0};
		bogosort(Arr);
		
		Console.Write(Arr[0]);
		for(int i = 1; i < Arr.Length; i++)
		{
			Console.Write(", " + Arr[i].ToString());
		}
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
