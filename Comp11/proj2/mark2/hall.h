#include <string>
using namespace std;

const int ROWS = 14;
const int COLS = 20;
const int SIZE = 7;
const double premium_price = 200.0;
const double general_price = 150.0;
const double deduction = .1;

class Hall
{
  public:

    Hall();

    bool request(string custID, int num, string price, string day);

    bool cancel(string custID);

    void print();

  private:

    string seating[ROWS][COLS];
    double pricing[ROWS][COLS];
};

