#include <iostream>
#include "persoana.h"
#include "postare.h"
#include "util.h"
#include "sandbox.h"

using namespace std;

int main()
{

    sandbox();
	test_util();
	testConsole();
 	testPostare();
    test_comentarii();
    cout << "\n";

    test_sugestii();
    return 0;
}
