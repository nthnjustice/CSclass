#include <iostream>
#include <stdio.h>
#include <ctype.h>

/* 
      3wordsort.cpp -- program to print out three words in alpha order
     usage: ./3wordsort
     input: three words
    output: the three words in alphabetical order, separated by spaces
      note: no prompt for user, no explanation on output
    
    modified by: Nathan Justice
    modified on: 2-6-13
 */

using namespace std;

void printInOrder(string, string, string);	// tell compiler about this

int main()
{
	string	w1,w2,w3;		// input values
	
	cin >> w1 >> w2 >> w3;		// read in three values
	printInOrder(w1,w2,w3);		// function does not return anything
	return 0;
}

//
// printInOrder() prints out the three words in alpha order
//		  with spaces between them, no return value
//
// your code here
	// your function does NOT use return
	// Instead, it sends values to cout
void printInOrder(string x, string y, string z)	
{
	
	if (x > y && x > z && y > z){
	  cout << z << " " << y << " " << x << endl;
	}
	if (y > x && y > z && x > z){
	  cout << z << " " << x << " " << y << endl;
	}
	if (z > x && z > y && x > y){
	  cout << y << " " << x << " " << z << endl;
	}
	if (z > x && z > y && y > x){
	  cout << x << " " << y << " " << z << endl;
	}
	if (x > z && x > y && z > y){
	  cout << y << " " << z << " " << x << endl;
	}
	if (y > z && y > x && z > x){
	  cout << x << " " << z << " " << y << endl;
	}
	
}


