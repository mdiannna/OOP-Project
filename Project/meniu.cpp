#include <bits/stdc++.h>
#include <stdlib.h>
// #include <conio.h>

#include "persoana.h"
#include "postare.h"
#include "view.h"
#include "colors.h"
#include "comentariu.h"
#include "sugestii.h"

using namespace std;


void adauga_comentariu()
{
    system("reset"); //system("cls");

    cout << "Introduceti numele persoanei care adauga comentariul: ";
    string nume;
    cin >> nume;

    Persoana *p = getPersoanaByString(nume);
    cout << "\nIntrodueti id ul postarii la care se adauga comentariul: ";

    int id;
    cin >> id;
    cout << "\nIntroduceti comentariul:\n";
// 
    string text;
    cin >> text;


    Comentariu c = creeazaComentariu(p, id, text);
}


void apreciaza_comentariu()
{
    system("reset"); //system("cls");

    cout << "Introduceti numele persoanei care apreciaza comentariul: ";
    string nume;
    cin >> nume;
    Persoana *p = getPersoanaByString(nume);

    cout << "\nIntroduceti id ul  postarii: ";
    int id;
    cin >> id;

    Postare *pp = getPostareById(id);
    pp->printComments();

    cout << "\nIntroduceti id ul comentariului: ";
    cin >> id;

    Comentariu *c = getComentariuById(id);
    c->add_like(p);
}


void afiseaza_sugestii()
{

    cout << "Introduceti numele persoanei pentru care sa se afiseze sugestii: ";
    string nume;
    cin >> nume;
    Persoana *p = getPersoanaByString(nume);
    Sugestie *s = new Sugestie(p);
    s->afiseaza_toate_sugestiile();
}


void afiseaza_sugestie()
{
     system("reset");

    cout << "Introduceti numele persoanei pentru care sa se afiseze o sugestie: ";
    string nume;
    cin >> nume;
    Persoana *p = getPersoanaByString(nume);
    Sugestie *s = new Sugestie(p);
    s->afiseaza_sugestie();
}



void creeazaPostare(){
    cout << "Introduceti id ul persoanei care posteaza: ";
    int id;
    cin >> id;

    cout << "Introduceti textul postarii: ";
    string text;
    cin >> text;
    Postare p =creeazaPostare(text, id);
}


void afiseazaToatePostarile(){
    View * view = new AllPostsView();
    cout << *view;
    delete(view);
}

void afiseazaPostareCuId(){
    cout << "Introduceti id ul postarii ce trebuie afisata: ";
    int id;
    cin >> id;

    View * view = new PostView(id);
    cout << *view;

    // delete(view);
}


void like_postare(){
    cout << "Introduceti id-ul postarii ";
    int id;
    cin >> id;

    Postare *p = getPostareById(id);
    p->addLike();
}


void afiseazaToatePersoanele(){
    View * view = new AllPersonsView();
    cout << *view;
    delete(view);   
}

void meniu()
{
    int choice = 0;

    do
    {
        View * meniu = new MenuView();
        cout << *meniu;

        delete(meniu);

        cin >> choice;
        cout << '\n';
        // system("reset");

        switch(choice)
        {
        case 1:
            creeazaPostare();
            break;
        case 2:
            afiseazaToatePostarile();
            break;
        case 3:
            afiseazaPostareCuId();
            break;
        case 4:
            adauga_comentariu();
            break;
        case 5:
            apreciaza_comentariu();
            break;
        case 6:
            afiseaza_sugestii();
        case 7:
            afiseaza_sugestie();
            break;
        case 8: 
            like_postare();
            break;
        case 9:
            afiseazaToatePersoanele();
            break;
        case 10:
            break;
        default:
            printError("Enter a valid selection!!!");
        }
    }while(choice != 10);
}
