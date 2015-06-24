#include <iostream>
/*
 * printlist.cpp  -- shows how to read a list of numbers into an array
 *
 *	1. First asks for the number of items in the list
 *	2. then uses a loop to read in that many values
 *	3. then prints out the list with line numbers using another loop
 */

using namespace std;

const int LIST_SPACE = 2000;		// size of array

int main()
{
	int	bdays[LIST_SPACE];	// where data are stored
	int	numItems;		// number of spaces used
	int	pos;			// position variable
	int	num_in_Oct=0;		//number of dates found in the month of October between the 1st and the 31st
	
	cout << "How many birthdays will you enter? ";
	cin  >> numItems;

	if ( numItems > LIST_SPACE ){
		cout << "I only have space for " << LIST_SPACE << endl;
		return 1;
	}

	// this loop is much shorter than
	//   cin >> bdays[0]
	//   cin >> bdays[1]
	//   cin >> bdays[2]
	//   ...
	for( pos=0; pos<numItems; pos = pos+1)
	{
		cin >> bdays[pos];
	}

	// now we can print out the list with numbers
	for( pos=numItems-1; pos>=0; pos--)
	{
		if((bdays[pos] >= 1001) && (bdays[pos] <= 1031)){
			cout << pos << ". " << bdays[pos] << endl;
			num_in_Oct++;
		}
		cout << num_in_Oct << endl;
	}

	return 0;
}

// I was only able to complete part 1 of this lab. However, I was told by the TA to provide anyways and not worry about it
