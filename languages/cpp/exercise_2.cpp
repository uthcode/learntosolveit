#include <iostream>
using namespace std;

class Box {

  public:

    int width, height;

    Box ();

    Box (int,int);

    int area(void)
    {
	    return (width*height);
    }

    int custom (void) {
	    cout<<"Enter width: ";
	    cin>>width;
	    cout<<"Enter height: ";
	    cin>>height;
	    return (width*height);
    }
};

// Constructor function
// Default Values
Box:: Box() {
	width = 5;
	height = 5;
}


// Constructor with Parameters
Box::Box (int a, int b) {
  width = a;
  height = b;
}

int main () {
  Box object1;
  cout <<"Default width = "<< object1.width<<endl;
  cout <<"Default height = "<<object1.height<<endl;
  cout <<"Default Area = "<<object1.area()<<endl;

  // Object with Parameters
  Box object2(10,10);
  cout << "New Width = " << object2.width << endl;
  cout << "New Height = " << object2.height << endl;
  cout << "Area = " << object2.area() << endl;

  // Copy Constructor
  
  Box object3 = object2;

  cout << "New Width = " << object3.width << endl;
  cout << "New Height = " << object3.height << endl;
  cout << "Area = " << object3.area() << endl;


  // Method taking input and returning value.

  // Uncomment the below line.

  // cout<<object2.custom();

  return 0;
}
