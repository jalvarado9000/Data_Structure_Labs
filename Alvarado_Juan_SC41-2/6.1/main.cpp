 #include<iostream>
 #include<cmath>
 using namespace std;

 struct Loan // Loan is called structure tag
 {
 int ID; // assume an unique integer between 1111-9999
 float amount; // $ amount of the loan
 float rate; // annual interest rate
 int term; // number of months, length of the loan
 };

 float payment(Loan l);
 void initialize_loan(Loan &loan1, Loan &loan2);

 int main( )
 {
 Loan loan1,loan2;
 float monthly_payment1,monthly_payment2;

 // Initialize the loan1 structure
 initialize_loan(loan1,loan2);
 monthly_payment1 = payment(loan1);
 monthly_payment2 = payment(loan2);

 cout << "The monthly payment for loan 1 " << loan1.ID << " is: " << monthly_payment1 << endl;
 cout << "The monthly payment for loan 2 " << loan2.ID << " is: " << monthly_payment2 << endl;

 return 0;
 }


 void initialize_loan(Loan &loan1, Loan &loan2){

 cout << "Enter the ID of this loan 1 \n";
 cin >> loan1.ID;
 cout << loan1.ID;

 cout << "Enter the ID of this loan 2 \n";
 cin >> loan2.ID;

 cout << "Enter the amount of loan 1 \n";
 cin >> loan1.amount;

 cout << "Enter the amount of loan 2 \n";
 cin >> loan2.amount;

 cout << "Enter the annual interest rate of  loan 2 (in %) \n";
 cin >> loan1.rate;

 cout << "Enter the annual interest rate of loan 2 (in %) \n";
 cin >> loan2.rate;

 cout << "Enter the term of loan 1(number of months, length of the loan) \n";
 cin >> loan1.term;

 cout << "Enter the term of loan 2 (number of months, length of the loan) \n";
 cin >> loan2.term;

 }




 float payment(Loan l)
 {
      l.rate = l.rate/1200; // To convert % yearly rate to monthly fraction
 return l.amount * l.rate * (pow((l.rate+1), l.term) / (pow((l.rate+1), l.term) -
1));
 }
