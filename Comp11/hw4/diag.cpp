/* 
      name:  diag.cpp -- draws diagnal patterns using loops, functions, and parameters
     usage: ./diag
     input: two strings and an int
    output: the pattern with specified height
      note: no loops in main, uses a function call
    
        by: Nathan Justice
  modified: 2/18/13
*/

# include <iostream>
using namespace std;

void draw_picture (string first_string, string second_string, int height); 


//this function gets values for the first and second string and the height the pattern is to be
int main ()
{
	string first_string, second_string;
	int height;
	
	cout << "First string? ";
	cin >> first_string ;
	cout << "Second string? " ;
	cin >> second_string ;
	cout << "Height? " ;
	cin >> height ;
	
	draw_picture (first_string, second_string, height) ; 
}
//draw_picture will draw the image, it uses the string inputs from main
//and outputs a diagonal pattern that is of the height inputted in main
//it doesn't return anything
void draw_picture (string first_string, string second_string, int height) {
	
	for (int i = 0; i < height; i++) {			//this loop sets the height
		for (int k = 0; k < i; k++) {			//this loop sets the numper of iterations for string 2
			cout << second_string ;
		}
		for (int s = 0; s < (height-i-1); s++) {	//this loop sets the number of iterations for string 1
			cout << first_string ;
		}
		
	cout <<  endl;
	}
}
	 
	 
	 

