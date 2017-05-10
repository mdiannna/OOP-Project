#ifndef TRIE_H_INCLUDED
#define TRIE_H_INCLUDED

#include "node.h"

#include <string>
#include <map>

using namespace std;

class trie
{
    public:
    node *rad;

    trie();

    bool find(string x);
    void insert(string x, int ind);
    void search(string x);
};


#endif // TRIE_H_INCLUDED
