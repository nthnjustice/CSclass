//
//adder8.cpp
//purpose: allows the user to add 8 numbers together and prints the sum
//by: Nathan Justice
// date: 1/26/12
//

#include <iostream>
using namespace std;

int main()
{
	double num = 0;
	double sum = 0;
	int i;
	
	cout << "Please enter eight floating point numbers." << endl;

	for(i = 1; i <= 8; i++){

		cout << "Enter number #" << i << " and press 'Return': ";
		cin >> num;
		sum = num + sum;
	} 
	
	cout << "The sum of the numbers is: ";
	cout << i << "." << endl;

	return 0;

}

