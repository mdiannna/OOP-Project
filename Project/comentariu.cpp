#include "util.h"
#include "trie.h"
#include "paire.h"
#include "persoana.h"
#include "comentariu.h"
#include "node.h"
#include <bits/stdc++.h>
#include <ctime>

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

Date Comentariu::getDate()
{
    return date;
}

Time Comentariu::getTime()
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
