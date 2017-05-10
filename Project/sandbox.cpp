
#include "sandbox.h"
#include "persoana.h"
#include "util.h"
#include "postare.h"
#include "sugestii.h"

#include <cstdio>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void sandbox()
{
    freopen("output.txt","w",stdout);
    Persoana *albert=new Persoana("albert");
    Persoana *ion=new Persoana("ion");
    Persoana *albert2=new Persoana("albert");
    Persoana *albu=new Persoana("albu");
    Persoana *ali=new Persoana("ali");
    Persoana *alex=new Persoana("alex");

    
    // for(auto it: Persoana::exist)
    // {
    //     cout<< it.first << " " << it.second <<"\n";
    // }
    

    ion->follow(albert);
    ion->follow(albert2);
    ion->follow(albu);
    ion->follow(ali);
    ion->follow(alex);
    albert->follow(albu);
    albert->follow(alex);

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


void test_util(){
    Date date;

    date.setDay(1);
    date.setMonth(2);
    date.setYear(2014);

    std::cout << "day:" << date.getDay() << "\n";
    std::cout << "month:" << date.getMonth() << "\n";
    std::cout << "year:" << date.getYear() << "\n";


    date.setDate(2, 4, 2013);

    std::cout << "day:" << date.getDay() << "\n";
    std::cout << "month:" << date.getMonth() << "\n";
    std::cout << "year:" << date.getYear() << "\n";

    std::cout << date.getDateAsString() << "\n";

    std::cout << getDateNowAsString() << "\n";
    std::cout << getTimeNowAsString() << "\n";
}



void testConsole(){
    printError("This is an error");
    printWarning("This is a warning");
    printSuccess("Success message");
}


void testPostare(){
    string test = "lalala";
    // functioneaza
    Postare postare1(test, 2);
    cout << postare1;
    
//     for(int i=0; i<150; i++)
//         test = test + "X";
//     // genereaza eroare
//     Postare *postare2 = new Postare(test, 2);
//     cout << *postare2;
// 
}

