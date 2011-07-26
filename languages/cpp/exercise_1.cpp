/** Write a program to create a class called fruit with a data member name,
category, weight, season & member function to accepting & displaying the data.
write a prog to test the class with three objs initialized first object default
values, 2nd obj by passing parameters 3rd by copy constructor. **/

#include <iostream>

using namespace std;

class Car {

	private:
		int model;
		int mileage;

	public:
		Car():
			model(10);
			mileage(100);

		void makecar(int model_parameter, int mileage_parameter)
		{
			model = model_parameter;
			mileage = mileage_parameter;
		}
};

int main()
{
	Car car_object;
	// Default values
	cout<<car_object.model<<endl;
	cout<<car_object.mileage<<endl;
}
