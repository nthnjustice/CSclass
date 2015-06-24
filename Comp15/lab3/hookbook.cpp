#include "hookbook.h"

HookBook::HookBook()
{
    hbook = new Pirate[INIT_CAPACITY];
    currentCapacity = INIT_CAPACITY;
    pirateCount = 0;
}


    /* Adds a new pirate to HookBook, probably the member should
       be created by the hookbook system, for now it is sent in
       from main, friends is a pointer to a dynamic array we
       copy it to the hookbook data structure, if it is null the pirate
       has no friend*/
    
bool HookBook::addPirate(int member, string nm)
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

    /* Prints the values in the list in ascending order. */
    /* This method is "const", which is a promise to the compiler
     that it won't change the value of any private variables. */
void HookBook::print() const
{
    cout << "There are " << pirateCount << " pirates in the system." << endl;
    for (int i = 0; i < pirateCount; i++) {
        cout << "Pirate: " << hbook[i].name << " with memberID: "
             << hbook[i].memberID << " has friends ";
        
        for(int j = 0; j < hbook[i].friendCount; j++)
        {
            cout << hbook[i].friendList[j] << " ";
        }
        
        cout << endl;
        
    }
}

    
 
//the function you will write you may have an empty list to start
bool HookBook::addFriend(int mem, int friendID)
{
  int tempI = 0;
  int tempII = 0;
  
  for(int i = 0; i < pirateCount; i++){
    if(hbook[i].memberID == mem){
      tempI = i;
    }
  }
  
  if(hbook[tempI].friendList == NULL){
    hbook[tempI].friendList = new int [hbook[tempI].friendCount];
  }
  
  if(hbook[tempI].friendCount >= hbook[tempI].friendCapacity){
    newExpand(tempI);
  }
  
  for(int i = 0; i < hbook[tempI].friendCount; i++){
    tempII = i;
  }
  
  hbook[tempI].friendList[tempII] = friendID;
  
  hbook[tempI].friendCount++;
  
  return true;
    
}

void HookBook::newExpand(int tempI)
{
  hbook[tempI].friendCapacity *= 2;
  
  int* temp = new int [hbook[tempI].friendCapacity];
  
  for(int i = 0; i < hbook[tempI].friendCount; i++){
    temp[i] = hbook[i].friendList[i];
  }
  
  delete [] hbook[tempI].friendList;
  
  hbook[tempI].friendList = temp;
}

/* destructor if you have time*/
HookBook::~HookBook()
{
    
}

bool HookBook::expandPirates()
{
    Pirate* temp = new Pirate[currentCapacity*2];
    if(temp == NULL){
        return false;
    }
    for (int i = 0; i < pirateCount; i++) {
        temp[i]=hbook[i];
    }
    delete[] hbook;
    hbook = temp;
    currentCapacity = currentCapacity*2;
    return true;
}

