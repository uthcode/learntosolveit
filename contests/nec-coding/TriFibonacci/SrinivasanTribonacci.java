import java.io.*;
import java.util.*;

class SrinivasanTrifibonacci
{
	public static void main(String args[]) throws IOException
	{
		int ans = -1, y, i;
		DataInputStream z = new DataInputStream(System.in);
		System.out.println("Enter the number of terms in the vector:");
		int n = Integer.parseInt(z.readLine());

		if (n > 3 && n < 21)
		{
			Vector<Integer> A = new Vector<Integer> (n);
			System.out.println("Enter the elements of the Vector one by one");

			for (i = 0; i < n; i++)
			{
				y = Integer.parseInt(z.readLine());

				if (y == -1 || (y > 0 && y < 1000001))
					A.add(i, y);
				else
				{
					System.out.println("Error: The Element should be from 1-1000000 or -1");
					break;
				}
			}
			if (n == i)
			{
				if (A.contains(-1))
				{
					FillTriFibonacci x = new FillTriFibonacci();
					ans = x.contains(A);
				}
				else
				{
					System.out.println("Error: The elements should contain -1");
				}

				if (ans > 0)
				{
					System.out.println("The Replacement is: " + ans);
				}
			}
		}
		else
			System.out.println("Error: Range is 4-20");
	}
}


class FillTriFibonacci
{
	public int contains(Vector<Integer> A)
	{
		int a, b, c, d, ans=-1, flag=0;
		for (int i=3; i < A.size(); i++)
		{
			a = A.get(i-3);
			b = A.get(i-2);
			c = A.get(i-1);
			d = A.get(i);

			if (a == -1 || b == -1 || c == -1 || d == -1)
			{
				if (flag != 0)
				{
					System.out.println("Error: More than one -1 is present in the vector");
					return -1;
				}
				flag = 1;
				if (a == -1)
				{
					ans = (d - (b + c));
					A.setElementAt(ans, i- 3);
				}
				else if (b == -1)
				{
					ans = (d - (a + c));
					A.setElementAt(ans, i-2);
				}
				else if (c == -1)
				{
					ans = (d - (a+b));
					A.setElementAt(ans, i-1);
				}
				else
				{
					ans = (a+b+c);
					A.setElementAt(ans, i);
				}
				i--;
				continue;
			}
			if (d != (a+b+c))
			{
				System.out.println("Error: The given series in not Trifibonacci");
				return -1;
			}
		}
		if (ans == 0 || ans < -1)
		{
			ans = -1;
			System.out.println("Error: No Positive Replacements can be made");
		}
		return ans;
	}
}
