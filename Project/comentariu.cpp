#include <bits/stdc++.h>
#include <ctime>

#include "trie.h"
#include "paire.h"
#include "persoana.h"
#include "comentariu.h"
#include "node.h"
#include "util.h"

using namespace std;

Comentariu::Comentariu(Persoana *pers, string _text)
{
    string nume = pers->name;
    author_id = pers->exist[nume];
    text = _text;
    date = getDateNow();
    time = getTimeNow();
    no_likes = 0;
}

int Comentariu::getAuthorId()
{
    return author_id;
}

int Comentariu::getNoLikes()
{
    return no_likes;
}

string Comentariu::getText()
{
    return text;
}

Date Comentariu::getDate() const
{
    return date;
}

Time Comentariu::getTime() const
{
    return time;
}

list<int> Comentariu::getPeopleLike()
{
    return people_like_ids;
}

void Comentariu::setText(string _text)
{
    text = _text;
}

void Comentariu::add_like(Persoana *pers)
{
    string nume = pers->name;
    int id = pers->exist[nume];

    people_like_ids.push_back(id);
    no_likes++;
}

ostream &operator <<(ostream & out, const Comentariu &comm)
{
    Persoana *pers = pers->give_back[comm.author_id];
    string nume = pers->who[pers->indice];

    Date d = comm.getDate();
    string dd = convertDateToString(d);

    Time t = comm.getTime();
    string tt = convertTimeToString(t);

    out << nume << " " << dd << " " << tt << " \n\n";
    out << comm.text << "\n\n\n";
}
