#include <iostream>
#include "persoana.h"

using namespace std;

int main()
{
    Persoana *albert=new Persoana("albert");
    Persoana *ion=new Persoana("ion");
    Persoana *albert2=new Persoana("albert");
    Persoana *albu=new Persoana("albu");
    Persoana *ali=new Persoana("ali");
    Persoana *alex=new Persoana("alex");

    /*
    for(auto it: Persoana::exist)
    {
        cout<< it.first << " " << it.second <<"\n";
    }
    */

    ion->follow(albert);
    ion->follow(albert2);
    ion->follow(albu);
    ion->follow(ali);
    ion->follow(alex);

    chat(ion, alex, 60);

    ion->search_following("al");

    return 0;
}
