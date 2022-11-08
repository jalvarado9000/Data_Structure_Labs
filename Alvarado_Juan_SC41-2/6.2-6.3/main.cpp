#include<iostream>
#include<cmath>
#include "loan.h"
using namespace std;

int main( )
{

    Loan loan1, loan2,loan3;
    //setter class function that takes user inputs
    loan1.set( );
    loan2.set();

    //displays the user inputs
    loan1.display();
    loan2.display();

    //sums the monthly payment of the two loans.
   cout << loan3.add_loans(loan1,loan2) << endl;

    return 0;
}
