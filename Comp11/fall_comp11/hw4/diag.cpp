//Nathan Justice
//10/3/12
//Homework assignment 4: Loops, Functions, Parameters
//This program will draw patterns, like diagonals, using loops, functions, parameters, and arrays

# include <iostream>
using namespace std;

void draw_picture (string first_string, string second_string, int height) ; 


//this part gets values for the first and second string and the height
int main ()
{
	string first_string, second_string ;
	int height;
	
	cout << "First string? ";
	cin >> first_string ;
	cout << "Second string? " ;
	cin >> second_string ;
	cout << "Height? " ;
	cin >> height ;
	
	draw_picture (first_string, second_string, height) ; 
}
//draw_picture will output a diagonal pattern
//user inputs first_string, second_string, and height
void draw_picture (string first_string, string second_string, int height) {
	
	for (int i = 0; i < height; i++) {	//this loop sets the height
		for (int k = 0; k < i; k++) {	//this loop sets the numper of iterations for string 2
			cout << second_string ;
		}
		for (int s = 0; s < (height-i-1); s++) {	//this loop sets the number of iterations for string 1
			cout << first_string ;
		}
		
	cout <<  endl;
	}
}
	 
	 
	 
	 
	 










