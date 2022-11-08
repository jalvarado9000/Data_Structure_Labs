#include "loan.h"//tell loan cpp where to find the class definition and functions.
#include "id.h"//tell loan cpp where to find the class definition and functions when using the id class member values or functions.


// This part will go to the Loan.cpp file
Loan::Loan()
{
}
Loan::Loan(ID I, float am, float rt, int trm)
{
   id = I;
      amount = am;
      rate = rt;
      term = trm;
}
void Loan::set( )
{
   int l, m, r;
      ID temp_id;
       // Initialize the loan1 object
      cout << "Enter the left part of the loan ID \n";
      cin >> l;
      cout << "Enter the middle part of the loan ID \n";
      cin >> m;
      cout << "Enter the right part of the loan ID \n";
      cin >> r;
      id = ID(l, m, r);
      cout << "Enter the amount of this loan \n";
      cin >> amount;
      cout << "Enter the annual interest rate of this loan (in %) \n";
      cin >> rate;
      cout << "Enter the term (number of months, length of the loan) \n";
      cin >> term;
}
void Loan::display()
{
     id.display();
     cout << amount << endl;
     cout << rate << endl;
     cout << term << endl;
}

