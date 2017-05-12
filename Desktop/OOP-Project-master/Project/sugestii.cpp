#include "sugestii.h"
#include "persoana.h"
#include "trie.h"
#include <stdlib.h>
#include <time.h>
#define NMAX 1000
#include <bits/stdc++.h>

using namespace std;

Sugestie::Sugestie(Persoana *pers)
{
    persoana_id = pers->indice;
    set<int> f = pers->list_follow;
    set<int> f1;
    set<int> f2;
    set<int>::iterator it, it2;
    for(it = f.begin(); it != f.end(); it++)
    {
        Persoana *p = getPersoanaById(*it);
        f2 = p->list_follow;
        set<int> ::iterator it2;
        for(it2 = f2.begin(); it2 != f2.end(); it2++)
        {
            f1.insert(*it2);
        }
    }
    it = f.begin();
    it2 = f1.begin();
    while(it2 != f1.end())
    {
        if(*it < *it2)
        {
             it++;
        }
        else if(*it2 == *it)
        {
            it2++;
            it++;
        }
        else
        {
            sugestii.push_back(*it2);
            it++;
        }
    }
}

void Sugestie::afiseaza_toate_sugestiile()
{
    if(sugestii.size())
    {
        cout << "Sugestii: \n";
        vector<int> ::iterator i;
        for(i = sugestii.begin(); i != sugestii.end(); i++)
        {
            cout << getPersoanaNameById(*i) << "\n";
        }
        cout << '\n';
    }
    else
    {
        cout << "Nu sunt sugestii de afisat\n\n";
    }
}

void Sugestie::afiseaza_sugestie()
{
    int n = sugestii.size();
    if(n)
    {
        srand (time(NULL));
        int i = rand() % n;
        cout << "Sugestie: \n" << getPersoanaNameById(i) << '\n';
    }
    else
    {
        cout << "Nu sunt sugestii de afisat\n\n";
    }
}
