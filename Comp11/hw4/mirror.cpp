/* 
      name:  mirror.cpp -- lists numbers in ascending sequential order and reflects them over the
      		'mirror' in descending sequential order
     usage: ./mirror
     input: one int
    output: the mirror pattern with specified max number
      note: no outut for negative number
    
        by: Nathan Justice
  modified: 2/18/13
*/

#include <iostream>
using namespace std;

int mirror(int max);

//this function gets a maximum value from the user and calls the function that
//out puts the desired mirror pattern
int main() 
{
	int max;
	
	cout << "Maximum value? " ;
	cin >> max ;
	if (max < 0){
	    return 0;
	}
	mirror(max);
}

//this function creates the mirror pattern by using the max number
//inputted from main, it returns the mirror pattern to main
int mirror(int max)
{
	int mirror;
	
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
	
	mirror = max;
	
	return mirror;
}

