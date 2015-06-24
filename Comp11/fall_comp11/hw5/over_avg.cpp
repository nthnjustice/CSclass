//Nathan Justice
//10-16-12
//Comp 11

#include <iostream>
using namespace std; 

const int SENTINEL = 0;
const int SPACE = 30000;
double average (int []);
int num_over_avg (int [], double);

//This program will read out the number of dates over the-
//average value.
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

//This function finds the value of-
// the average of the birthyears.
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

//This function finds the numer of-
//birthyears that are over the 
//average value.
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
