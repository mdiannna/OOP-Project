#include "persoana.h"
#include "trie.h"
#include <map>
#include <string>

using namespace std;

int Persoana::no_pers=0;
map<string, int> Persoana:: exist;
map<int, string> Persoana:: who;

Persoana::Persoana(string nume)
{
    while(exist[nume])
    {
        nume=nume+"$";
    }
    Persoana::no_pers++;

    exist[nume]=no_pers;
    who[no_pers]=nume;

    name=nume;
    indice=no_pers;
    followers=new trie;
    following=new trie;
}


void Persoana::follow(Persoana *alta)
{
    if(following->find(alta->name)==0)
    {
        alta->isfollowed(this);
        following->insert(alta->name, alta->indice);
    }

}

void Persoana::isfollowed(Persoana *alta)
{
    followers->insert(alta->name, alta->indice);
}

void Persoana::search_following(string x)
{
    following->search(x);
}

void Persoana::search_followers(string x)
{
    followers->search(x);
}

void chat(Persoana *a, Persoana *b, int minute)
{

}
