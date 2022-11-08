 #include<iostream>
 #include<cmath>
 using namespace std;

 class Loan // Loan is called structure tag
 {
 public:
 Loan();
 Loan(int ID, float amount, float rate, int term);
 void set();
 void payment();//calculate and set the monthly payment.
 void display();//show the objects member values.
 float add_loans(Loan,Loan);*//sums two objects monthly payment values.
 private:
 int ID; // assume an unique integer between 1111-9999
 float amount; // $ amount of the loan
 float rate; // annual interest rate
 int term; // number of months, length of the loan
 float monthly_payment; //the amount of money to be paid monthly by the user.
 };

 int main()
 {
 Loan loan1(1234, 2300, 5.5, 48); // initialize to values given
 Loan loan2; // use the default values
 Loan loan3;//uses assigned user values
 Loan loan4 = loan1;
 Loan loan_sum1, loan_sum2;

 cout << "Display loan1 \n";
 loan1.display();

 cout << "Display loan2 \n";
 loan2.display();

 cout << "Display loan4 \n";
 loan4.display();

 loan3.set( ); // set the values
 cout << "Display loan3 \n";
 loan3.display();

 //sums the value of loan1 and loan2 monthly payments
 cout << "Display sum of loan1 and loan2" << endl;
 cout << loan_sum1.add_loans(loan1,loan2)<<endl;
  //sums the value of loan3 and loan4 monthly payments
 cout << "Display sum of loan3 and loan4" << endl;
 cout << loan_sum2.add_loans(loan3,loan4)<< endl;

 return 0;
 }

 Loan::Loan()
 {
// Body intentionally kept empty so the default values are used.
// If you wish to set the default value of the members to specific
// values, here is the place to do it.
// For example, to make the default value of amount = 0
// you will use amount = 0;

 // You could actually copy the body of set function here too

 }

 Loan::Loan(int I, float am, float rt, int trm)
 {
 ID = I;
 amount = am;
 rate = rt;
 term = trm;

 }

 void Loan::set()
 {
 // Initialize the loan3 object
 cout << "Enter the ID of this loan \n";
 cin >> ID;

 cout << "Enter the amount of this loan \n";
 cin >> amount;

 cout << "Enter the annual interest rate of this loan (in %) \n";
 cin >> rate;

 cout << "Enter the term (number of months, length of the loan) \n";
 cin >> term;
 }

 //displays each loan objects member values.
 void Loan::display()
 {
 cout << ID << endl;
 cout << amount << endl;
 cout << rate << endl;
 cout << term << endl;
 payment();
 cout << monthly_payment << endl;
}

void Loan:: payment()
{
      //to verify that its not diving 0/1200.
      if(rate > 0){
      rate = rate/1200;  // To convert % yearly rate to monthly fraction
      monthly_payment = amount*rate*(  pow( (rate+1), term)/ (pow( (rate+1), term) - 1) );

      }
      //if it is assign zero to monthly payment.
      else
        monthly_payment = 0;
}

//takes two objects monthly payment and return the total sum.
float Loan::add_loans(Loan loan1, Loan loan2){


loan1.monthly_payment + loan2.monthly_payment;
return loan1.monthly_payment + loan2.monthly_payment;
}

