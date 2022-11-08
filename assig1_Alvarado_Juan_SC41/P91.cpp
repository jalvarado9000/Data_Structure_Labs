//Juan M. Alvarado Caraballo
//S01035309

#include <iostream>
#include "id.h"//includes the id header and id cpp in the main
#include "loan.h"//includes the loan header and loan cpp in the main

using namespace std;

// This part will go to the main program, main_prog.cpp
int main( )
{
    Loan loan1(ID(111,22,4444), 2300, 5.5, 48);  // initialize to values given
    Loan loan2;
    cout << "Display loan1 \n";
    loan1.display();
    loan2.set( ); // set the values
    cout << "Display loan2 \n";
    loan2.display();
    return 0;
}
