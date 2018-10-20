import java.util.*;
class Main
{
	public static void main(String args[])
	{
		int a[], n, i, temp, j;
		Scanner sc = new Scanner(System.in);
		System.out.println("\nEnter the number of elements: ");
		n = sc.nextInt();
		a = new int[n];
		for(i=0; i<n; i++)
			a[i] = sc.nextInt();
		for(i=0; i<n-1; i++)
		{
			for(j=0; j<n-1-i; j++)
			{
				if(a[j] > a[j+1])
				{
					temp = a[j];
					a[j] = a[j+1];
					a[j+1] = temp;
				}
			}
		}
		System.out.println("\nSorted array is:");
		for(i=0; i<n; i++)
			System.out.println(a[i]);
	}
}



