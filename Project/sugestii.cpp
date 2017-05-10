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
    person = pers;
    set<int> s;
    set<paire> follow_sugg = pers->ordonati;
    set<paire>::iterator it;
    for(it = follow_sugg.begin(); it != follow_sugg.end(); it++)
    {
        string nume = it->nume;
        int i = pers->exist[nume];
        s.insert(i);
    }
    set<int>::iterator it2;
    set<int> follower2;
    for(it2 = s.begin(); it2 != s.end(); it2++)
    {
        Persoana *pers2= pers->give_back[*it2];
        follow_sugg = pers2->ordonati;
        for(it = follow_sugg.begin(); it != follow_sugg.end(); it++)
        {
            string nume = it->nume;
            int i = pers->exist[nume];
            follower2.insert(i);
        }
    }
    for(it2 = follower2.begin(); it2 != follower2.end(); it++)
    {
        int i = *it2;
        Persoana *pers2 = pers->give_back[i];
        sugestii.push_back(i);
    }
}

void Sugestie::afiseaza_toate_sugestiile()
{
    cout << "Sugestii: \n";
    vector<int> ::iterator i;
    for(i = sugestii.begin(); i != sugestii.end(); i++)
    {
        cout << person->who[*i] << "\n";
    }
    cout << '\n';
}

void Sugestie::afiseaza_sugestie()
{
    int n = sugestii.size();
    srand (time(NULL));
    int i = rand() % n;
    cout << "Sugestie: \n" << person->who[i] << '\n';
}
