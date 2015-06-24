#include <iostream>
using namespace std;
//
// pat1.cpp  -- draw a checkerboard pattern
//  version1: draws 8 rows of 8 chars alternating X and -
//  Goal: allow user to enter two strings and 
//		the number of pairs per line
//		the number lines per set
//		the number sets per image
//
//  tools: loops and functions(with arguments)
//


void twoLines(string s1, string s2, int reps);

int main()
{
    int count = 0;
    string s1, s2;
    int pair_per_row;
    int number_rows;
 
    cout << "Please enter two strings: ";
    cin >> s1 >> s2 ;
    cout << "Enter the number of strings per row:";
    cin >> pair_per_row;
    cout << "Enter the number of pairs of rows:";
    cin >> number_rows;

    while(count < number_rows)
{				
	twoLines(s1, s2, pair_per_row);
	count++;
    }
}
void twoLines(string one, string two, int reps){
    int count = 0;
    while(count < reps){
	cout << one << two;
	count++;
     }
    cout << endl;
    count = 0;
    while(count < reps){
	cout << two << one;
	count++;
    }
    cout << endl;
}
