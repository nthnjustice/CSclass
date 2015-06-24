/***********************************************************************/
/*                        FrequencyTable2 Interface                    */
/***********************************************************************/
/*  A minimal implementation of a Frequency Table.                     */
/*  Author:  Nathan Justice                                            */
/*                                                                     */
/*  A list is either:                                                  */
/*    -empty                                                           */
/*    -non-empty node containing:                                      */
/*      - a struct Head                                                */
/*      - an Node tail                                                 */
/*                                                                     */
/*  Operations:                                                        */
/*  (see functions below for parameter/type information)               */
/*    FrequencyTable(): initializes an empty list                     */
/*    in(): goes to private_in()                                       */
/*    insert(): goes to private_insert()                               */
/*    frequency(): goes to private_frequency()                         */
/*    size(): goes to private_size                                     */
/*    get(): goes to private_get                                       */
/*    destroy(): goes to private_destroy                               */
/*    private_in(): checks if a word is in the list                    */
/*    private_insert(): adds a word to the lift if it is not already   */
/*                        present                                      */
/*  private_frequency(): finds the frequency of a word in the list     */
/*  private_size(): finds the size of the list                         */
/*  private_get(): finds the n-th node in the list                     */
/*  private_destroy(): clears and destroys the list                    */
/*  word_again(): checks if a word is already present in the list      */
/*  wordsize(): finds the size of a word in the array                 */
/*  whatnode(): finds the node that a word is in                       */
/*  addnode(): adds a new node if a word isn't present in the list     */
/*  head_data(): fills the head with a word and a frequency            */
/***********************************************************************/


#include <iostream>
using namespace std;

#include "WordFreqList.h"

const int LETTERS = 26;//number of letters in the alphabet

class FrequencyTable
{
  public:
    FrequencyTable();
    bool in(string word);
    void insert(string word);
    int frequency(string word);
    int size();
    void get(int i, string *ptrToWord, int *ptrToFrequency);
    void destroy();
  private:
    WordFreqList list[LETTERS];//the linked list

    void private_constuctor();
    bool private_in(string word);
    void private_insert(string word);
    int private_frequency(string word);
    int private_size(WordFreqList templist[]);
    void private_get(int i, string *ptrToWord, int *ptrToFrequency);
    void private_destroy();
    bool word_again(string word, WordFreqList Node1);
    int wordsize(WordFreqList temp);
    WordFreqList whatnode(string word);
    void addnode(string word);
    Head head_data(string word);
};
