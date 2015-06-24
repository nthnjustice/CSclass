#include <iostream>
using namespace std;

#include "WordFreqList.h"

Head fill(string);

int main()
{

  WordFreqList list = empty();
  Head head;
  string word;

  cin >> word;
  head = fill(word);

  if(isEmpty(list)){
    list = prepend(head, list);
  }

  cin >> word;
  head = fill(word);

  insertAfter(list, head);

  while(list != NULL){
    cout << list->wfpair.frequency << " ";
    cout << list->wfpair.word << endl;
    list = list->tail;
  }

  return 0;

}

Head fill(string word)
{

  Head data;

  data.word = word;
  data.frequency = 3;

  return data;

}
