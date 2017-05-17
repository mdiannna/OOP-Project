#ifndef PERSOANA_H_INCLUDED
#define PERSOANA_H_INCLUDED

#include "trie.h"
#include "paire.h"

#include <vector>
#include <map>
#include <set>
#include <thread>
#include <mutex>

using namespace std;

class Persoana
{
    public:
    static int no_pers;
    static map<string,int> exist;
    static map<int, string> who;
    static map<int, Persoana*> give_back;

    map<Persoana *, int> scor;
    set<paire> ordonati;

    static mutex global_mutex;
    mutex changing_mutex;

    string name;
    int indice;
    trie *followers, *following;
    set<int> list_follow;

    Persoana(){}
    Persoana(string nume);

    Persoana* getPersoanaByNo(int no);
    Persoana* getPersoanaByString(string x);
    void follow(Persoana *alta);
    void isfollowed(Persoana *alta);
    void search_following(string x) const;
    void search_followers(string x) const;
    void show_friends(int no) const;
    static void make_chat(Persoana *a, Persoana *b, int minute);
    static void create_person(char *v);
    static void read_chatting(char *v);
    static void begin_chatting(int pas);
    static void begin_creation(int pas);
    static void read_followings(char *v);
    static void begin_followings(int pas);

    void friend chat(Persoana *a, Persoana *b, int minute);

    friend ostream &operator<<(ostream &, const Persoana&);

};
//map<string, int> Persoana::exist;

// Non class member functions
Persoana * getPersoanaById(int);
string getPersoanaNameById(int);
Persoana* getPersoanaByString(string);

void printAllPersons();

#endif // PERSOANA_H_INCLUDED
