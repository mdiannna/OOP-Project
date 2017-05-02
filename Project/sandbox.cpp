#include "sandbox.h"
#include "persoana.h"


void sandbox()
{
    freopen("output.txt","w",stdout);
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
    chat(ion, alex, 10);

    chat(ion, albert, 65);
    chat(ali,ion, 20);
    chat(ali, albert, 100);

    ion->show_friends(10);

    ion->search_following("al");

    Persoana::create_person("nume.txt");
    Persoana::read_chatting("chat.txt");

    Persoana::read_followings("follow.txt");
}
