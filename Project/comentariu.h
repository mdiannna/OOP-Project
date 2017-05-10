#ifndef COMENTARIU_H_INCLUDED
#define COMENTARIU_H_INCLUDED

#include "util.h"
#include "trie.h"
#include "paire.h"
#include "persoana.h"
#include "node.h"
#include <bits/stdc++.h>
#include <ctime>

using namespace std;

class Comentariu
{
    int author_id;
    string text;
    Date date;
    Time time;
    int no_likes;
    list<int> people_like_ids;
public:
    Comentariu(Persoana *pers, string _text);

    int getAuthorId();
    string getAuthorName();
    int getNoLikes();
    string getText();
    Date getDate();
    Time getTime();
    list<int> getPeopleLike();

    void setText(string _text);
    void add_like(Persoana *pers);

    friend ostream& operator << (ostream &, Comentariu );

};

#endif // COMENTARIU_H_INCLUDED

