#include "loan.h"
#include <iostream>
#include <cmath>
using namespace std;
void Loan::set( )
{
       // Initialize the loan1 and loan2 objects
      cout << "Enter the ID of this loan \n";
      cin >> ID;
      cout << "Enter the amount of this loan \n";
      cin >> amount;
      cout << "Enter the annual interest rate of this loan (in %) \n";
      cin >> rate;
      cout << "Enter the term (number of months, length of the loan) \n";
      cin >> term;
}

void Loan::display(){

      //displays loan1 and loan2 objects
      cout << "The ID of this loan \n";
      cout << ID << endl;
      cout << "The amount of this loan \n";
      cout << amount << endl;;
      cout << "The annual interest rate of this loan (in %) \n";
      cout << rate << endl;
      cout << "The term (number of months, length of the loan) \n";
      cout << term << endl;
      cout << "The Monthly payment is: \n";
      payment();
      cout << monthly_payment << endl;


}


void Loan:: payment()
{
      rate = rate/1200;  // To convert % yearly rate to monthly fraction
      monthly_payment = amount*rate*(  pow( (rate+1), term)/ (pow( (rate+1), term) - 1) );
}

//takes two objects monthly payment and return the total sum.
float Loan::add_loans(Loan loan1, Loan loan2){

float sum;
sum = loan1.monthly_payment + loan2.monthly_payment;
return sum;
}
