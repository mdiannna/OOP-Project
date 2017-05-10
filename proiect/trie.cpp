#include "trie.h"

trie::trie()
{
    rad=new node;
}

bool trie::find(string x)
{
    const char *v=x.c_str();

    return rad->find(v);
}

void trie::insert(string x, int ind)
{
    const char *v=x.c_str();

    rad->insert(v, ind);
}

void trie::search(string x)
{
    const char *v=x.c_str();

    rad->search(v);
}
