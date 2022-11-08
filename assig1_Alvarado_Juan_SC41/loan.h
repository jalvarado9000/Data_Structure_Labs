//tells the compiler that if the class has been define once do not define it again.
#ifndef LOAN_H
#define LOAN_H

#include <iostream>
#include "id.h"//tell loan cpp where to find the class definition and functions when using the id class member values or functions.
using namespace std;
// This part will go to Loan.h file
class Loan  // Loan class definition
{
   public:
     Loan( );
     Loan(ID id, float amount, float rate, int term);
     void set( );
     float payment( );
     void display( );
   private:
      ID id;  // assume an unique integer in three integer parts
      float amount; // $ amount of the loan
      float rate; // annual interest rate
      int term;  // number of months, length of the loan
 };

 //tells the compiler this is the end of the defined class
#endif // LOAN_H

