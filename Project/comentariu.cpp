#include <bits/stdc++.h>
#include <ctime>

#include "trie.h"
#include "paire.h"
#include "persoana.h"
#include "comentariu.h"
#include "node.h"
#include "util.h"
#include "console.h"
#include "postare.h"
#include "colors.h"

using namespace std;

int Comentariu::last_id = 0;

Comentariu::Comentariu()
{

}

Comentariu::Comentariu(Persoana *pers, int id_postare, string _text)
{
    string nume = pers->name;
    post_id = id_postare;
    author_id = pers->exist[nume];
    text = _text;
    date = getDateNow();
    time = getTimeNow();
    no_likes = 0;

    last_id++;
    id = last_id + 1;

    comentarii.insert({id, this});

    Postare* post = getPostareById(id_postare);

    printSuccess("Comentariu adaugat la postarea ");
    printSuccess(id_postare);
    cout << "\n";

    post->addComment(id);
}

int Comentariu::getId() const
{
    return id;
}

int Comentariu::getPostId() const
{
    return post_id;
}

int Comentariu::getAuthorId() const
{
    return author_id;
}

int Comentariu::getNoLikes() const
{
    return no_likes;
}

string Comentariu::getText() const
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
    cout  << "ID postare:" << comm.post_id << "\n";
    Persoana *pers = pers->give_back[comm.author_id];
    string nume = pers->who[pers->indice];

    Date d = comm.getDate();
    string dd = convertDateToString(d);

    Time t = comm.getTime();
    string tt = convertTimeToString(t);

    int nr = comm.getNoLikes();

    out << "          --------------COMMENT----" << comm.getId() << "--------\n";
    out << "          ";
    printBlue("@" + nume);
    out << "          ";
    printGreen(dd);
    out << "          ";
    printRed(tt);
    out << " \n";
    out << "          ";
    out << comm.getText() << "\n\n";
    out << "          ";
    printCyan(nr);
    if(nr >= 1 || nr == 0)printCyan(" likes\n\n");
    else printCyan(" like\n\n");
    out << "\n          ---------------------------------\n";

    return out;
}



ostream &operator <<(ostream & out, const Comentariu * comm)
{
    // cout  << "ID postare:" << comm->post_id << "\n";
    // Persoana *pers = pers->give_back[comm->author_id];
    // string nume = pers->who[pers->indice];

    Date d = comm->getDate();
    string dd = convertDateToString(d);

    Time t = comm->getTime();
    string tt = convertTimeToString(t);

    int nr = comm->getNoLikes();

    out << "          --------------COMMENT----" << comm->getId() << "--------\n";
    out << "          ";
    // printBlue("@" + nume);
    out << "          ";
    printGreen(dd);
    out << "          ";
    printRed(tt);
    out << " \n";
    out << "          ";
    out << comm->getText() << "\n\n";
    out << "          ";
    printCyan(nr);
    if(nr >= 1 || nr == 0)printCyan(" likes\n\n");
    else printCyan(" like\n\n");
    out << "\n          ---------------------------------\n";

    return out;
}



Comentariu * getComentariuById(int id_cautat)
{
    return comentarii[id_cautat];
}
