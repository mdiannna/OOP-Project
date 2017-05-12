#ifndef SUGESTII_H_INCLUDED
#define SUGESTII_H_INCLUDED

#include "trie.h"
#include "paire.h"
#include "persoana.h"
#include "node.h"
#include <bits/stdc++.h>

using namespace std;

class Sugestie
{
    int persoana_id;
    vector<int> sugestii;
public:
    Sugestie(Persoana *pers);
    void afiseaza_toate_sugestiile();
    void afiseaza_sugestie();

};

#endif // SUGESTII_H_INCLUDED
