#include <iostream>
#include "persoana.h"
#include "postare.h"
#include "util.h"
#include "sandbox.h"
#include "view.h"

using namespace std;

int main()
{
    sandbox();
	test_util();
	testConsole();
 	testPostare();
    test_comentarii();

    cout << "\n";
    cout << "\n\n------------\n";

    printAllPosts();
    //test_sugestii();

    testView();

    return 0;
}
