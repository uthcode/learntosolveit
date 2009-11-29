#include <iostream>
#include <algorithm>
using namespace std;
main()
{
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int count = 0;
	do
	{
		if ( ( a[0] + a[1] + a[2] ) == 17 &&
			 ( a[0] + a[3] + a[6] ) == 17 &&
			 ( a[2] + a[5] + a[8] ) == 17 &&
			 ( a[2] + a[4] + a[6] ) == 17 &&
			 ( a[6] + a[7] + a[8] ) == 17 )
		{
			cout <<count << " : ";
			for ( int i = 0 ; i <9 ; i++ )
				cout <<a[ i ] <<" ";
			cout <<"\n";
		}
		count++;
	} while ( next_permutation( a, a + 9 ) );
	cout <<count <<" permutations were tested\n";
	return 0;
}
