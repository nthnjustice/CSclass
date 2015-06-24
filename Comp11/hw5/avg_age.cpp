/* 
      name:  avg_age.cpp -- prints the average age of a specific name
     usage: ./avg_age
     input: birthyears, names and sentinel
    output: average age of specified name
      note: has space for only 50000 years and names and requires entry
      		of a sentinel
    
        by: Nathan Justice
  modified: 2/24/13
*/

#include <iostream>
using namespace std;

const int SENTINEL = -1;
const int SPACE = 50000;
double average (int birthyear[], string name[], string avg_name);
const int CURRENT_YEAR = 2013;

/* This program takes in birthyears and names and prints the
   average age of a specified name by calling a function */
int main()
{
	string avg_name;
	int birthyear[SPACE];
	string name[SPACE];
	int yr;
	string entry_name;
	int pos = 0;
	double avg_value;
	
	do {
		cin >> yr;
		cin >> entry_name;
		birthyear[pos] = yr;
		name [pos] = entry_name;
		if (pos > SPACE){
			cout << "too much data" << endl;
			return 1;
}
		pos++;	
}
	
	while (yr != SENTINEL);
		
	cout << "Enter a name:" << endl;
	cin >> avg_name;
	avg_value = average (birthyear, name, avg_name);
	if (avg_value == 0){
		cout << "name not found" << endl;
}else{
		cout << "average age = " << avg_value << endl;
}	
	return 0;
}	

/* This function finds the average age of a given name from the
  data inputted. */
double average (int birthyear[], string name[], string avg_name)
{
	int pos = 0;
	double sum = 0.0;
	int age = 0;
	double avg = 0.0;
	int count_of_name = 0;
			
	while (birthyear[pos] != SENTINEL){
		if (name[pos] == avg_name){
			age = (CURRENT_YEAR - birthyear[pos]);
			count_of_name++;
			sum += age;
}
		pos++;
}
	if (count_of_name == 0){
		return 0;
}
	avg = sum / count_of_name;
	return avg;
}

