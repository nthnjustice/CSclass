/***********************************************************************/
/*                          WordFreqList Interface                     */
/***********************************************************************/
/* A minimal implementation of linked lists.                           */
/* Author:  Nathan Justice                                             */
/*                                                                     */
/* A list is either:                                                   */
/*      -empty                                                         */
/*      -non-empty node containing:                                    */
/*           - a struct Head                                           */
/*           - an Node tail                                            */
/*                                                                     */
/* Operations:                                                         */
/* (see functions below for parameter/type information)                */
/*      empty()      : returns an empty list                           */
/*      isEmpty()    : used to check if the given list is empty        */
/*      prepend()    : returns a newly allocated list node with the    */
/*                     given data value in the head and the given list */
/*                     in the tail                                     */
/*      head()       : returns the data value in the head of the       */
/*                     given non-empty list node.                      */
/*                     It is an error to call head() on an empty list. */
/*      tail()       : returns the list Node in the tail of the given  */
/*                     non-empty list node.                            */
/*                     It is an error to call tail() on an empty list. */
/*      deleteHead() : returns the list Node in the tail of the given  */
/*                     list.                                           */
/*                     Frees storage associated with a non-empty node. */
/*                     It is an error to call deleteHead() on an       */
/*                     empty list.                                     */
/*     insertAfter() : void function that inserts a new node in the    */
/*                     list after a specific existing node             */
/*     set_freq()    : void function that sets the frequency of a node */
/*                     to a new frequency.                             */
/*                                                                     */
/***********************************************************************/
#include <iostream>
using namespace std;

//struct represents the head of each node in the linked list
struct Head{
  string word;
  int frequency;
};

//struct represents each node present in the linked list
struct Node{
  Head wfpair;
  Node *tail;
};

//new type that is a pointer of type Node:
//a variable of this type points to a Node in the linked list
typedef Node *WordFreqList;

WordFreqList empty();
bool isEmpty(WordFreqList);
WordFreqList prepend(Head, WordFreqList);
Head head(WordFreqList);
WordFreqList tail(WordFreqList);
WordFreqList deleteHead(WordFreqList);
void insertAfter(WordFreqList, Head);
void set_freq(WordFreqList, int);
