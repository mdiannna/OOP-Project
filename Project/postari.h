#ifndef POSTARI_H_INCLUDED
#define POSTARI_H_INCLUDED

#include <iostream>
using namespace std;

class Postare{
    char * text;
    //Persoana persoana;
    enum nivelDeIntimitate{
        toti,
        prieteni,
        followeri
    };
public:
    void postManager();
};


#endif // POSTARI_H_INCLUDED
