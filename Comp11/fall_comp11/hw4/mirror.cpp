//Nathan Justice
//10/3/12
//Homework assignment 4:Loops, Functions, Parameters
//This program will take input and then repeat a mirror image of the input stream across a line refered to as "the mirror"

#include <iostream>
using namespace std;

//this part gets a maximum value from the user
int main() 
{
	int max;
	
	cout << "Maximum value? " ;
	cin >> max ;
	
	while (max < 0) {
		cin >> max ;
	}
	
	for (int i = 0; i < 4; i++) {			//this loop sets the number of iterations for the mirror, a.k.a. the height or number of rows
		for (int k = 0; k <= max; k++) { 	//this loops outputs the max value in numerical order
			cout << k ;
		}
		
		cout << "|" ;
		
		for (int k = max; k >= 0; k--) {	//this loop outputs the mirrored max value in descening numerical order
			cout << k ;
		}
		cout << endl;
	}
}








