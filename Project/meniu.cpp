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
    system("reset");
}


void apreciaza_comentariu()
{

}


void afiseaza_sugestii()
{

}


void afiseaza_sugestie()
{

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
