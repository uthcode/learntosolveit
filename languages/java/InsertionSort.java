
import java.util.*;
class Main
{
	public static void main(String args[])
	{
		int a[], n, i, temp, j;
		int val,hole=1;
		Scanner sc = new Scanner(System.in);
		System.out.println("\nEnter the number of elements: ");
		n = sc.nextInt();
		a = new int[n];
		for(i=0; i<n; i++)
			a[i] = sc.nextInt();
		for(i=1; i<n; i++)
		{
			hole=i;
			val=a[i];
			while(hole>0&&val<a[hole-1])
			{
				a[hole] = a[hole-1];
				hole--;
			}
			a[hole]=val;
		}
		System.out.println("\nSorted array is:");
		for(i=0; i<n; i++)
			System.out.println(a[i]);
	}
}




