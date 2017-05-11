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
    static int last_id;
    int id;
    int author_id;
    int post_id;
    string text;
    Date date;
    Time time;
    int no_likes;
    list<int> people_like_ids;
public:
    Comentariu(Persoana *pers, int id_postare, string _text);

    int getId() const;
    int getPostId() const;
    int getAuthorId() const;
    string getAuthorName();
    int getNoLikes() const;
    string getText();
    Date getDate() const;
    Time getTime() const;
    list<int> getPeopleLike();

    void setText(string _text);
    void add_like(Persoana *pers);

    friend ostream& operator << (ostream &, const Comentariu &);

};

#endif // COMENTARIU_H_INCLUDED

