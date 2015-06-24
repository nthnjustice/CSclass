/*****************************************************************************
name: WordFreqList.cpp
purpose: defines the functions used by FrequenyTable1 and FrequencyTable2
usage: fnctions called by FrequencyTable1 an FrequencyTable2
input: n/a
output: n/a
note: this program has no main an therefore is very modulare by design
by: Nathan Justice
modified:4/19/13
*****************************************************************************/


#include <iostream>
using namespace std;

#include "WordFreqList.h"

/******************************************************************************
purpose: returns an empty list
input: n/a
returns: an empty list (NULL)
******************************************************************************/
WordFreqList empty()
{
  return NULL;//represents an empty Node
}

/******************************************************************************
purpose: used to check if a node in the linked list is empty or not
input: pointer to a list
returns: when called, returns true if the given list is empty, and false
         otherwise
******************************************************************************/
bool isEmpty(WordFreqList list)
{
  return list == NULL;//represents an empty Node
}

/******************************************************************************
purpose: returns a newly allocated list node with the given data value in the
         head and the given list in the tail
input: new data for a struct of type Head, a pointer to a list
returns: a pointer to a new Node that is 'placed' at the the beginning of
         the list
******************************************************************************/
WordFreqList prepend(Head new_data, WordFreqList list)
{
  Node *p_node = new Node;//temporary pointer to a Node

  p_node->wfpair = new_data;
  p_node->tail = list;

  return p_node;
}

/******************************************************************************
purpose: find the data in the head of the given non-empty node. It is an error
         to call head() on an empty list.
input: a pointer to a list
returns: returns the data value in the head
******************************************************************************/
Head head(WordFreqList list)
{
  return list->wfpair;//head of a Node
}

/******************************************************************************
purpose: goes to the list Node in the tail of the given non-empty list node.
         this allows the program to navigate through the Nodes of the list
input: a pointer to a list
returns: the list Node in the tail
******************************************************************************/
WordFreqList tail(WordFreqList list)
{
  return list->tail;//tail of a Node
}

/******************************************************************************
purpose: frees storage associated with a non-empty node. It is an error to
         call deleteHead() on an empty list.
input:  a pointer to a list
returns: returns the IntList in the tail of the given
******************************************************************************/
WordFreqList deleteHead(WordFreqList list)
{
  WordFreqList rest_list = tail(list);
  delete list;//kills the Node

  return rest_list;//returns the remainder of the list
}

/******************************************************************************
purpose: void function that inserts a new node in the list after a specific
         existing node
input: a pointer to a list, new data of type Head (includes a word and
       frequency
returns: n/a
******************************************************************************/
void insertAfter(WordFreqList list, Head new_data)
{
  WordFreqList insert = new Node;//temporary Node

  insert = prepend(new_data, list->tail);

  list->tail = insert;
}

/******************************************************************************
purpose: void function that sets the frequency of a node to a new frequency.
input: a pointer to a list, frequency
returns: n/a
******************************************************************************/
void set_freq(WordFreqList list, int freq)
{
  list->wfpair.frequency = freq;
}
