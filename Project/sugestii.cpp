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
    set<int>::iterator it;
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
    for(it = f1.begin(); it != f1.end(); it++)
        if(f.find(*it))sugestii.push_back(*it);

}

void Sugestie::afiseaza_toate_sugestiile()
{
    cout << "Sugestii: \n";
    vector<int> ::iterator i;
    for(i = sugestii.begin(); i != sugestii.end(); i++)
    {
        cout << getPersoanaNameById(*i) << "\n";
    }
    cout << '\n';
}

void Sugestie::afiseaza_sugestie()
{
    int n = sugestii.size();
    srand (time(NULL));
    int i = rand() % n;
    cout << "Sugestie: \n" << getPersoanaNameById(i) << '\n';
}
