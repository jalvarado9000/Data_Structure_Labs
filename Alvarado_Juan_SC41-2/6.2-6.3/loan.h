#ifndef LOAN_H
#define LOAN_H


class Loan  // Loan is called structure tag
{

   private:
       int ID;  // assume an unique integer between 1111-9999
       float amount; // $ amount of the loan
      float rate; // annual interest rate
      int term;  // number of months, length of the loan
      float monthly_payment; //amount of payment made every month.


      public:
         void set( );//set the id, amount, rate, term values
         void payment( );//calculate and display the monthly payment
         void display( );//outputs the id, amount, rate, term values given by the user
         float add_loans(Loan,Loan);//total sum of the montlhy payments of two Loans.
 };


#endif // LOAN_H
