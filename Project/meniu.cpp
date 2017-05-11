#include <bits/stdc++.h>
#include "persoana.h"
#include "postare.h"
#include "view.h"
#include "colors.h"
#include "comentariu.h"
#include "sugestii.h"

using namespace std;


void adauga_comentariu()
{

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
            printRed("Enter a valid selection!!!");
        }
    }while(choice != 8);
}
