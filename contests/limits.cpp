#include <iostream>
#include <ostream>
#include <limits>

int main()
{
typedef std::numeric_limits< double > dl;
typedef std::numeric_limits< float > fl;

using namespace std;

cout << "double:\n";
cout << "\tdigits (bits):\t\t" << dl::digits << endl;
cout << "\tdigits (decimal):\t" << dl::digits10 << endl;

cout << endl;

cout << "float:\n";
cout << "\tdigits (bits):\t\t" << fl::digits << endl;
cout << "\tdigits (decimal):\t" << fl::digits10 << endl;
}
