#include <iostream>
//
// adder8.cpp
// purpose: add eight numbers
// by: Nathan Justice
// date: 9/20/12
//
using namespace std;
int main()
{
    double a,b,c,d,e,f,g,h, sum;
    cout << "Enter eight numbers: ";
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;
    cin >> e;
    cin >> f;
    cin >> g;
    cin >> h;
    sum = a + b + c + d + e + f + g + h;
    cout << "The sum is " << sum << endl;
    return 0;
}
