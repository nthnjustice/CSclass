//
//  pat.cpp  -- draw a checkerboard pattern
//  version1: draws 8 rows of 8 chars alternating X and -
//  Goal: allow user to enter two strings and 
//		the number of pairs per line
//		the number lines per set
//		the number sets per image
//
//  tools: loops and functions(with arguments)
//

//Nathan Justice
//comp11
//2-6-13
//lab4

#include <iostream>

using namespace std;

void twolines(string s1, string s2, int reps);

int main()
{
  int counter = 0;
  string s1, s2;
  int num_pairs_string;
  int num_rows;
  
  cout << "Please enter your first string: " << endl;
  cin >> s1;
  cout << "Please enter your second string: " << endl;
  cin >> s2;
  cout << "Please enter the number of pairs of strings per row: " << endl;
  cin >> num_pairs_string;
  cout << "Please enter the number of pairs of rows: " << endl;
  cin >> num_rows;
  
  while(counter < num_rows){
    twolines(s1, s2, num_pairs_string);
    counter++;
  }
  
  return 0;
  
}

void twolines(string s1, string s2, int reps)
{
  int counter = 0;
  
  while(counter < reps){
    cout << s1 << s2;
    counter++;
  }
  
  cout << endl;
  counter = 0;
  
  while(counter < reps){
    cout << s2 << s1;
    counter++;
  }
  
  cout << endl;
}
  
  
 



