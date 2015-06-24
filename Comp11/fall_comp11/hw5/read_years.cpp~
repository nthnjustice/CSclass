//Nathan Justice
//10-16-12
//comp 11

#include <iostream>
using namespace std;
//
// read_years.cpp - demo of sentinel
//
const int SPACE = 1000;       // space in the array
const int SENTINEL = -1;   // input sentinel

void print_list(int nums[]);
double average(int nums[]);

int main()
{
        int years[SPACE];
        int pos = 0;
        int y;
        double avg;

        do {
                cin >> y;
                years[pos++] = y;
		
		if (pos > SPACE){
			cout << "too much input\n";
		return 1;
		}
        }
        while( y != SENTINEL );

        print_list(years);
        avg = average(years);
        cout << "avg=" << avg << endl;
        return 0;
}

// print a list of numbers, list is
// terminated by a sentinel
void print_list(int nums[])
{
        int pos = 0;
        while( nums[pos] != SENTINEL ){
                cout << pos << " " << 
	        nums[pos] << endl;
                pos++;
        }
}

// returns the average (mean) value
// of the integers in the list
double average(int list[])
{
	int pos = 0;
	double sum = 0;
					
	while( list[pos] != SENTINEL ){
		sum += list[pos];
		pos++;
	}
	return sum/pos;
}
