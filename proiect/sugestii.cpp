#include "persoana.h"
#include "trie.h"
#include <map>
#include <string>
#include <iostream>
#include <bits/bits/stdc++.h>

using namespace std;

set<trie*>suggestions;

void Sugestie::search_f(string x)
{

}

void Sugestie::suggest(Persoana *pers)
{
    trie *_following = pers->following;
    suggestions = new set<Persoana>
    for(auto it:_following)
    {
        trie *ff = it
    }
}
