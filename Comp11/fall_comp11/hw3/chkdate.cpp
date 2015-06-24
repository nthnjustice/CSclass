//Nathan Justice
// 9-27-12

#include <iostream>
using namespace std;

int main()
{
	const int Jan = 1, Feb = 2, Mar = 3, Apr = 4, May = 5, Jun = 6, Jul = 7, Aug = 8, Sep = 9, Oct = 10, Nov = 11, Dec = 12;
	
	int month, day, year;
	
	cin >> month >> day >> year;
	
	// conditions
	if ((month < 1) || (month > 12) || (day < 1) || (year < 1) || (year > 9999)){ 
		cout << "N" << endl;
	}
	
	// for months that have only 30 days
	else if (((month == Apr) || (month == Jun) || (month == Sep) || (month == Nov)) && (day <= 30)){
		cout << "Y" << endl;
	}
	
	// for months that have 31 days
	else if (((month == Jan) || (month == Mar) || (month == May) || (month == Jul) || (month == Aug) || (month == Oct) || (month == Dec)) && (day <= 31)){
		cout << "Y" << endl;
	}
	
	// for February
	else if ((month == Feb && day <= 28) || (day <=29 && (year % 4) == 0 && (year % 100) != 0)){
		cout << "Y" << endl;
		else if (year % 4) && (year % 400)
	}
			 
	else { 
		cout << "N" << endl;
	}
	
}





