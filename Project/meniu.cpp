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



void creeazaPostare(){

}


void afiseazaToatePostarile(){
    printAllPosts();
}

void afiseazaPostareCuId(){

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
        // system("clear");
        
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

            break;
        default:
            printError("Enter a valid selection!!!");
        }
    }while(choice != 8);
}
