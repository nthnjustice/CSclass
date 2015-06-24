#include "hookbook.h"

classyPirate::classyPirate()
{
    hbook = new Pirate[INIT_CAPACITY];
    currentCapacity = INIT_CAPACITY;
    pirateCount = 0;
}


    /* Adds a new pirate to classyPirate, probably the member should
       be created by the hookbook system, for now it is sent in
       from main, friends is a pointer to a dynamic array we
       copy it to the hookbook data structure, if it is null the pirate
       has no friend*/
    
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

    /* Prints the values in the list in ascending order. */
    /* This method is "const", which is a promise to the compiler
     that it won't change the value of any private variables. */
void classyPirate::print() const
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
bool FriendList::addFriend(int mem, int friendID)
{
    
    //lookup
    int index = 0;
    for(int i = 0; i < pirateCount; i++)
    {
        if (hbook[i].memberID == mem) {
            index = i;
        }
    }
    
    
    //handle null case
    if (classyPirate.hbook[index].friendList == NULL) {
        hbook[index].friendList = new int[INIT_CAPACITY];
        hbook[index].friendCapacity = INIT_CAPACITY;
    }
    
    
    //expand
    if (hbook[index].friendCount >= hbook[index].friendCapacity) {
        int* temp = new int[hbook[index].friendCapacity*2];
        if(temp == NULL)
        {
            return false;
        }
        
        for (int i = 0; i < hbook[index].friendCount; i++) {
            temp[i] = hbook[index].friendList[i];
        }
        delete hbook[index].friendList;
        hbook[index].friendList = temp;
        hbook[index].friendCapacity = hbook[index].friendCapacity*2;
    }
    
    //finally add a friend
    hbook[index].friendList[hbook[index].friendCount] = friendID;
    hbook[index].friendCount++;
    return true;
}
    
/* destructor if you have time*/
classyPirate::~classyPirate()
{
    
}

bool classyPirate::expandPirates()
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

