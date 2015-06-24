/*
 * printsequence.cpp  -- shows how to read a list of numbers into an array
 *
 *	1. First asks for the number of items in the list
 *	2. then uses a loop to read in that many values
 *	3. then prints out the list with line numbers using another loop
 */
#include <iostream>

using namespace std;

const int ARRAY_SPACE = 2000;

int main() 
{
        int bdays[ARRAY_SPACE];   // where data are stored
        int numItems;             // number of spaces used
        int pos;                  // position variable

        cout << "How many birthdays will you enter? ";
        cin  >> numItems;

        if (numItems > ARRAY_SPACE) {
                cout << "I only have space for " << ARRAY_SPACE << endl;
                return 1;
        }

        // this loop is much shorter than
        //   cin >> bdays[0]
        //   cin >> bdays[1]
        //   cin >> bdays[2]
        //   ...
        for (pos = 0; pos < numItems; pos = pos + 1) {
                cin >> bdays[pos];
		
	  if (bdays[pos] < 1001){
		   for (pos = (numItems-1); pos >= 0; pos = pos - 1) {
                cout << (numItems - pos) << ". " << bdays[pos] << endl;
		   }
	  }
	}
	
        
	
	
		
        return 0;
}
