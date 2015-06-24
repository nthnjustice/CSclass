/*****************************************************************************
name: FrequencyTable2.cpp
purpose: defines all the functions present in FrequencyTable2.h
usage: functions are used to run the program wordfreq.cpp
input: n/a
output: n/a
note: this program is a faster version of FrequencyTable1.cpp
by: Nathan Justice
modified: 4/19/13
*****************************************************************************/

#include <iostream>
using namespace std;

#include "FrequencyTable2.h"

/******************************************************************************
purpose: calls the private constructor
input: n/a
returns: n/a
******************************************************************************/
FrequencyTable::FrequencyTable()
{
  private_constuctor();
}

/******************************************************************************
purpose: initializes an empty list
input: n/a
returns: n/a
*****************************************************************************/
void FrequencyTable::private_constuctor()
{
  for(int i = 0; i < LETTERS; i++){
    list[i] = empty();//sets the Node to NULL
  }
}

/******************************************************************************
purpose: calls the private insert function
input: word
returns: n/a
*****************************************************************************/
void FrequencyTable::insert(string word)
{

  private_insert(word);

}

/******************************************************************************
purpose: calls the private in function
input: word
returns: n/a
*****************************************************************************/
bool FrequencyTable::in(string word)
{
  return private_in(word);
}

/******************************************************************************
purpose: calls the private frequency function
input: word
returns: n/a
*****************************************************************************/
int FrequencyTable::frequency(string word)
{
  return private_frequency(word);
}

/******************************************************************************
purpose: calls the private size function
input: n/a
returns: n/a
*****************************************************************************/
int FrequencyTable::size()
{
  return private_size(list);
}

/******************************************************************************
purpose: calls the private get function
input: integer, a pointer to a word in the list and a pointer to the frequency
        of a word in the list
returns: n/a
*****************************************************************************/
void FrequencyTable::get(int i, string *ptrToWord, int *ptrToFrequency)
{
  private_get(i, ptrToWord, ptrToFrequency);
}

/******************************************************************************
purpose: calls the private destroy function
input: n/a
returns: n/a
*****************************************************************************/
void FrequencyTable::destroy()
{
  private_destroy();
}

/******************************************************************************
purpose: sets a word to the word in the head of a Node
input: word and a pointer to a Node
returns: a new word assigned to the word present in the head of the Node 
          that is pointed to
*****************************************************************************/
bool FrequencyTable::word_again(string word, WordFreqList Node1)
{
  return word == head(Node1).word;
}

/******************************************************************************
purpose: checks if a word is in the list
input: word
returns: true if the word exists in the list, false if the word is novel
*****************************************************************************/
bool FrequencyTable::private_in(string word)
{
  WordFreqList temp = list[word[0] - 'a'];//all the letters

  while(!isEmpty(temp)){
    if(word_again(word, temp)){
      return true;
    }
    else{
      temp = tail(temp);
    }
  }

  return false;
}

/******************************************************************************
purpose: adds a word to the lift if it is not already present
input: word
returns: n/a
*****************************************************************************/
void FrequencyTable::private_insert(string word)
{
  WordFreqList tempNode = empty();

  if(in(word)){//if the word is already in the list
    tempNode = whatnode(word);
    set_freq(tempNode, frequency(word) + 1);//increases the frequency
  }
  else{//if the word is not already in the list
    addnode(word);//adds the word to the list
  }
}

/******************************************************************************
purpose: finds the frequency of a word in the list
input: word
returns: the number of times a word appears in the list as an int
*****************************************************************************/
int FrequencyTable::private_frequency(string word)
{
  WordFreqList temp = list[word[0] - 'a'];

  while(!isEmpty(temp)){
    if(word_again(word, temp)){//if the word is already in the list
      return head(temp).frequency;
    }
    else{
      temp = tail(temp);
    }
  }
    return 0;
}

/******************************************************************************
purpose: inds the size of the list 
input: a temporary array of type pointer
returns: the size of the list as an integer
*****************************************************************************/
int FrequencyTable::private_size(WordFreqList templist[])
{
  WordFreqList temp;
  int size = 0;

  for(int i = 0; i < LETTERS; i++){
    temp = templist[i];
    size += wordsize(temp);
  }

  return size;//size of the list
}

/******************************************************************************
purpose: finds the size of a word in the array
input: a temporary pointer
returns: the number of characters in a word in the list
*****************************************************************************/
int FrequencyTable::wordsize(WordFreqList temp)
{
  if(isEmpty(temp)){
    return 0;
  }

  return 1 + wordsize(tail(temp));//size of the word as letters
}

/******************************************************************************
purpose: finds the n-th node in the list
input: integer, a pointer to a word in the list and a pointer to the frequency
returns: n/a
*****************************************************************************/
void FrequencyTable::private_get(int i, string *ptrToWord, int *ptrToFrequency)
{
  int j = 0;
  WordFreqList temp = list[j];

  while(isEmpty(temp)){
    j++;
    temp = list[j];
  }

  for(int k = 0; k < i; k++){
    if(!isEmpty(temp)){
      temp = tail(temp);
      while(isEmpty(temp)){
	j++;
        temp = list[j];
      }
    }
  }

  *ptrToWord = head(temp).word;//points to the word
  *ptrToFrequency = frequency(*ptrToWord);//points to the frequency
}

/******************************************************************************
purpose: clears and destroys the list 
input: n/a
returns: n/a
*****************************************************************************/
void FrequencyTable::private_destroy()
{
  for(int i = 0; i < LETTERS; i++){
    while(!isEmpty(list[i])){
      list[i] = deleteHead(list[i]);//kills the list
    }
  }
}

/******************************************************************************
purpose: finds the node that a word is in  
input: word
returns: a pointer to a Node in the list
*****************************************************************************/
WordFreqList FrequencyTable::whatnode(string word)
{
  WordFreqList temp = list[word[0] - 'a'];

  while(!word_again(word, temp)){
    temp = tail(temp);
  }

  return temp;//returns a pointer to the Node the word is in
}

/******************************************************************************
purpose: adds a new node if a word isn't present in the list
input: word
returns: n/a
*****************************************************************************/
void FrequencyTable::addnode(string word)
{
  WordFreqList before;//preceding pointer
  WordFreqList after;//following pointer
  int i = word[0] - 'a';

  if(isEmpty(list[i])){
    list[i] = prepend(head_data(word), list[i]);
  }
  else{
    if(word < head(list[i]).word){
      list[i] = prepend(head_data(word), list[i]);
    }
    else{
      after = list[i];

      while(!isEmpty(after) && word > head(after).word){
	before = after;
	after = tail(after);
      }

      insertAfter(before, head_data(word));
    }
  }
}

/******************************************************************************
purpose:fills the head with a word and a frequency 
input: word
returns: a new Head with the word and a frequency of 1
*****************************************************************************/
Head FrequencyTable::head_data(string word)
{
  Head temp;

  temp.word = word;
  temp.frequency = 1;

  return temp;
}
