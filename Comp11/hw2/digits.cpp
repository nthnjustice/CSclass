// iftest.cpp
//      purpose: report number of digits in an integer
//        shows: use of output, input, conditional statements
//         note: has bugs, needs work
//
//  modified by:Nathan Justice
//         date:1/25/13
//

#include <iostream>
using namespace std;

int main()
{
	int input;

	cout << "Enter a number: ";
	cin  >> input;

	if (input == 0){
		cout << "input has one digit and input is 0" << endl;
	}
	
	else if (input >= 100 || input <= -100) {
		cout << "input has three or more digits";	
	} 
	
	else if (input >= 10 || input <= -10) {
		cout << "input has two digits";
	} 
	
	else if (input >= 1 || input <= -10) {
		cout << "input has one digit";
	}
	
	else if (input  -1 && input >= -9) {
		cout <<"input has one digit";
	}
		
	if (input > 0){
		cout << " and input is positive" << endl;
	}
	
	if (input < 0){	
		cout << " and input is negative" << endl;

	}
	
        return 0;
}
