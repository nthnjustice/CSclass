#include <iostream>
using namespace std;

#include "WordFreqList.h"

const int LETTERS = 26

class FrequencyTable
{
  public:
    FrequencyTable();
    bool in(string word);
    void insert(string word);
    int frequency(string word);
    int size();
    void get(int n, string *ptrToWord, int *ptrToFrequency);
    void destroy();
  private:
    WordFreqList list[LETTERS];
    Head fill_head(string word);
    WordFreqList whatnode(string word);
    void addnode(string word);

    bool private_in(string word);
    void private_insert(string word);
    int private_frequeny(string word);
    int private_size();
    void private_get(int n, string *ptrToWord, int *ptrToFrequency);
    void private_destroy();
};
