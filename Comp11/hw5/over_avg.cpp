/* 
      name:  over_avg.cpp -- calculates the average of inputted
      		values and prints the number of data entries over
      		the calculated average
     usage: ./over_avg
     input: years and sentinel
    output: number of years over the average
      note: has space for only 30000 years and requires entry of a 
      		sentinel
    
        by: Nathan Justice
  modified: 2/24/13
*/

#include <iostream>
using namespace std; 

const int SENTINEL = 0;
const int SPACE = 30000;
double average (int []);
int num_over_avg (int [], double);
/* The program reads in dates, calls a function that caluculates
   the average and calls a second function that calculates the number
    of years that are over the average */
int main()
{	int years[SPACE];
	int pos = 0;
	int yr;
	double avg; 
	
	do {
		cin >> yr;
		years[pos++] = yr;
		
		if (pos > SPACE){
			cout << "too much input\n";
			return 1;
		}
	}
		
	while (yr != SENTINEL);
	
	avg = average(years);
	cout << num_over_avg (years, avg) << endl;
	
	return 0;
}
/* This function finds the value of average of the birthyears. */
double average(int list[])
{
	int pos = 0;
	double sum = 0;
	
	while (list[pos] != SENTINEL){
		sum += list[pos];
		pos ++;
	}
	return sum/pos;
}
/* This function finds the numer of birthyears that are over the 
   average value. */
int num_over_avg (int list[], double avg)
{	
	int pos = 0;
	int count = 0;
	
	while (list[pos] != SENTINEL){
		if (list[pos] > avg){
			count++;
		}
		pos++;
	}
	return count;
}
