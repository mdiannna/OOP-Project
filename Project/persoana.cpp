#include "persoana.h"
#include "trie.h"
#include <map>
#include <string>
#include <iostream>
#include <thread>
#include <mutex>
#include <fstream>

using namespace std;

int Persoana::no_pers=0;
map<string, int> Persoana:: exist;
map<int, string> Persoana:: who;
map<int, Persoana*> Persoana:: give_back;
mutex Persoana:: global_mutex;

//afisare

ostream &operator<<(ostream &out, const Persoana& pers){


    out<<"Persoana are numele "<<pers.name<<"\n";
    out<<"Top 10 prieteni, dupa conversatii sunt\n";

    pers.show_friends(10);
    out<<"\n";

    return out;
}


//afisare





Persoana* getPersoanaById(int id)
{
    Persoana *pers = pers->give_back[id];
    return pers;
}

string getPersoanaNameById(int id)
{
    Persoana *pers = pers->give_back[id];
    string nume = pers->who[pers->indice];
    return nume;
}


Persoana* getPersoanaByString(string x)
{
    Persoana *pers = new Persoana();
    return pers->give_back[pers->exist[x]];
}



Persoana* Persoana::getPersoanaByNo(int no)
{
    return give_back[no];
}

Persoana* Persoana::getPersoanaByString(string x)
{
    return give_back[exist[x]];
}



Persoana::Persoana(string nume)
{
    Persoana::global_mutex.lock(); //deci a fost degeaba impartirea pe thread-uri, dar macar se vede ca merge lock si unlock
    while(exist[nume])
    {
        nume=nume+"$";
    }

    Persoana::no_pers++;
    exist[nume]=no_pers;

    who[exist[nume]]=nume;


    Persoana::give_back[exist[nume]]=this;


    Persoana::global_mutex.unlock();

    name=nume;
    indice=exist[nume];


    followers=new trie;
    following=new trie;


}


void Persoana::follow(Persoana *alta)
{
    if(alta==this)
        return;

    lock_guard<mutex> lock(changing_mutex);
    if(following->find(alta->name)==0)
    {
        alta->isfollowed(this);
        following->insert(alta->name, alta->indice);
    }
    list_follow.insert(alta->indice);
}

void Persoana::isfollowed(Persoana *alta)
{
    lock_guard<mutex> lock(changing_mutex);
    followers->insert(alta->name, alta->indice);
}

void Persoana::search_following(string x)
{
    cout<<"oameni urmariti care incep cu prefixul \""<<x<<"\" \n";
    following->search(x);

    cout<<"\n";
}

void Persoana::search_followers(string x)
{
    cout<<"oameni care ma urmaresc si incep cu prefixul \""<<x<<"\" \n";
    followers->search(x);

    cout<<"\n";
}

void Persoana:: make_chat(Persoana *a, Persoana *b, int minute)
{
    // mutex ordonati_mutex;

    lock_guard<mutex> lock(a->changing_mutex);

    paire aux=paire{b->name, a->scor[b]};

    if(a->ordonati.find(aux)!=a->ordonati.end())
    {
        a->ordonati.erase(aux);
    }

    a->scor[b]+=minute;

    aux=paire{b->name,a->scor[b]};
    a->ordonati.insert(aux);

    //cica nu trebuie sa ii dau unlock la a->ordonati_mutex, caci isi da singur
}


void chat(Persoana *a, Persoana *b, int minute)
{
    thread t1(Persoana::make_chat, a, b, minute);
    thread t2(Persoana::make_chat, b, a, minute);

    //https://askubuntu.com/questions/568068/multithreading-in-codeblocks

    t1.join();
    t2.join();
}

void Persoana::show_friends(int no) const
{
    cout<<"top "<<no<<" ai lui "<<this->name<<"\n";
    std::set<paire>::iterator it=ordonati.begin();

    if(it==ordonati.end())
    {
        cout<<"none\n";
    }

    for(int i=1; i<=no && it!=ordonati.end(); i++)
    {
        cout<<it->nume<<" "<<it->scor<<"\n";
        it++;
    }
    cout<<"\n";
}

vector<string> fst,sec;
vector<int> mn;

void Persoana::begin_followings(int pas)
{
    for(int i=pas; i<fst.size(); i+=4)
    {
        if(exist[fst[i]]==0 || exist[sec[i]]==0)
            continue;

        give_back[exist[fst[i]]]->follow(give_back[exist[sec[i]]]);
    }
}

void Persoana::read_followings(char *v)
{
    ifstream in(v);

    string nume1,nume2;

    while(in>>nume1)
    {
        in>>nume2;
        fst.push_back(nume1);
        sec.push_back(nume2);
    }


    thread t1(Persoana::begin_followings, 0);
    thread t2(Persoana::begin_followings, 1);
    thread t3(Persoana::begin_followings, 2);
    thread t4(Persoana::begin_followings, 3);

    t1.join();
    t2.join();
    t3.join();
    t4.join();



    fst.clear();
    sec.clear();
}




void Persoana::begin_creation(int pas)
{
    for(int i=pas; i<fst.size(); i+=4)
    {
        //cout<<pas<<endl;
        Persoana *aux=new Persoana(fst[i]);
    }
}

void Persoana::create_person(char *v)
{
    ifstream in(v);

    string num;

    while(in>>num)
    {
        fst.push_back(num);
    }

    thread t1(Persoana::begin_creation, 0);
    thread t2(Persoana::begin_creation, 1);
    thread t3(Persoana::begin_creation, 2);
    thread t4(Persoana::begin_creation, 3);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    fst.clear();
}


void Persoana::begin_chatting(int pas)
{
    for(int i=pas; i<fst.size(); i+=4)
    {
        if(exist[fst[i]]==0 || exist[sec[i]]==0)
            continue;

        //cout<<fst[i]<<" "<<sec[i]<<" "<<pas<<"\n";
        chat(give_back[exist[fst[i]]], give_back[exist[sec[i]]], mn[i]);
    }
}

void Persoana::read_chatting(char *v)
{
    ifstream in(v);

    string nume1,nume2;
    int minut;

    while(in>>nume1)
    {
        in>>nume2>>minut;
        fst.push_back(nume1);
        sec.push_back(nume2);
        mn.push_back(minut);
    }

    thread t1(Persoana::begin_chatting, 0);
    thread t2(Persoana::begin_chatting, 1);
    thread t3(Persoana::begin_chatting, 2);
    thread t4(Persoana::begin_chatting, 3);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    fst.clear();
    sec.clear();
    mn.clear();
}
void printAllPersons(){
    for(auto it: Persoana::exist)
    {
        cout<< it.first << " ";
        cout << (it.second) <<"\n";
    }
}