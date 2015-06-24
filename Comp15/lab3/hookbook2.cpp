#include <iostream>
using namespace std;

int main()
{
  return 0;
}

classyPirate::classyPirate()
{
  hbook = new Pirate[INIT_CAPACITY];
  currentCapacity = INIT_CAPACITY;
  pirateCount = 0;
}

bool classyPirate::addPirate(int member, string nm)
{
  //check to see if we need to expand to add
  if(pirateCount >= currentCapacity)
  {
    // check to see if expand worked
    if(!expandPirates())
    {
      return false;
    }
  }
  //made it here so we can add a pirate
  hbook[pirateCount].memberID = member;
  hbook[pirateCount].name = nm;
  hbook[pirateCount].friendList = NULL;
  hbook[pirateCount].friendCount = 0;
  hbook[pirateCount].friendCapacity = 0;
  pirateCount++;
  return true;
}