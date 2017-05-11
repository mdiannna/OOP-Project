#include <bits/stdc++.h>
#include <stdlib.h>

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

    string text;
    cin >> text;

    Comentariu *c = new Comentariu(p, id, text);
    Postare *post = getPostareById(id);
    post->addComment(c->getId());
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
    system("reset"); //system("cls");

    cout << "Introduceti numele persoanei pentru care sa se afiseze sugestii: ";
    string nume;
    cin >> nume;
    Persoana *p = getPersoanaByString(nume);
    Sugestie *s = new Sugestie(p);
    s->afiseaza_toate_sugestiile();
}


void afiseaza_sugestie()
{
     system("reset"); //system("cls");

    cout << "Introduceti numele persoanei pentru care sa se afiseze o sugestie: ";
    string nume;
    cin >> nume;
    Persoana *p = getPersoanaByString(nume);
    Sugestie *s = new Sugestie(p);
    s->afiseaza_sugestie();
}


void meniu()
{
    int choice = 0;

    do
    {
        printBlue("Console Tweet 2017 Menu\n");
        printBlue("=======================\n");
        printWhite("1. \n");
        printWhite("2. \n");
        printWhite("3. \n");
        printWhite("4. Adauga comentariu\n");
        printWhite("5. Apreciaza un comentariu\n");
        printWhite("6. Afiseaza persoane sugerate pentru a fi urmarite\n");
        printWhite("7. Afiseaza o persoana sugerata pentru a fi urmarita\n");
        printWhite("8. Exit\n");
        printBlue("=======================\n");
        printBlue("Enter your selection:\n");
        cin >> choice;
        cout << '\n';
        switch(choice)
        {
        case 1:
        case 2:
        case 3:
        case 4:
            void adauga_comentariu();
            break;
        case 5:
            void apreciaza_comentariu();
            break;
        case 6:
            void afiseaza_sugestii();
        case 7:
            void afiseaza_sugestie();
            break;
        case 8:

            break;
        default:
            printError("Enter a valid selection!!!");
        }
    }while(choice != 8);
}
