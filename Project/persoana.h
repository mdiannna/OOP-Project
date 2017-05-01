#ifndef PERSOANA_H_INCLUDED
#define PERSOANA_H_INCLUDED

#include "trie.h"

#include <vector>
#include <map>

using namespace std;

class Persoana
{
    public:
    static int no_pers;
    static map<string,int> exist;
    static map<int, string> who;

    string name;
    int indice;
    trie *followers, *following;

    Persoana(string nume);

    void follow(Persoana *alta);
    void isfollowed(Persoana *alta);
    void search_following(string x);
    void search_followers(string x);

    void friend chat(Persoana *a, Persoana *b, int minute);

};
//map<string, int> Persoana::exist;


#endif // PERSOANA_H_INCLUDED
