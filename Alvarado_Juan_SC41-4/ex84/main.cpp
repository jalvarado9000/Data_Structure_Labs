// P84.cpp - This program is a driver written to demonstrate how we can use a
// class inside another one.
#include<iostream>
using namespace std;

class ID
{
   public:
      ID();//default constructor
      ID(int, int, int);//constructor with parameters
      void display();//display the number of the ID for the Loan
      int get_left();//gets the left ID value
      int get_middle();//gets the middle ID value
      int get_right();//gets the right ID value

   private:
      int left;//stores the left ID value
      int middle;//stores the middle ID value
      int right;//stores the right ID value
};

class Loan  // Loan is called structure tag
{
   public:
      Loan();//default constructor
      Loan(ID id, float amount, float rate, int term);//constructor with parameters
      void set();//sets the user input values
      void display();//show the id, amount, rate and term values.
      friend bool operator == (Loan m, Loan n);//operator overload ==
   private:
      ID id;  // assume an unique integer between 1111-9999
      float amount; // $ amount of the loan
      float rate; // annual interest rate
      int term;  // number of months, length of the loan
};

int main()
{
   //initialize the loan1 object and the ID object.
   Loan loan1(ID(111,22,4444), 2300, 5.5, 48);  // initialize to values given
   Loan loan2;

   //display the loan1 object data members
   cout << "Display loan1 \n";
   loan1.display();

   //initialize the loan2 data members
   loan2.set(); // set the values

   //display the loan2 data members
   cout << "Display loan2 \n";
   loan2.display();


   cout << "Are Loan1 and Loan2 the same?" << endl;

   //checks if loan1 and loan2 are the same
   if(loan1 == loan2)
    cout << "Yes" << endl;
   else
        cout << "No" << endl;

   return 0;
}

ID::ID()
{
   // use default values
}

ID::ID(int l, int m, int r)
{
   //sets the value l,m,r values to the private data members
   left = l;
   middle = m;
   right = r;
}


void ID::display()
{
   cout << left << "-" << middle << "-" << right << endl;
}

//ID class getters
int ID::get_left(){return left;}
int ID::get_right(){return right;}
int ID::get_middle(){return middle;}



Loan::Loan()
{
}

Loan::Loan(ID I, float am, float rt, int trm)
{
   //sets the I,am,rt,trm to Loan class private data members
   id = I;
   amount = am;
   rate = rt;
   term = trm;
}

void Loan::set()
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

   //pass the l,m,r value to the ID constructor with parameters
   id = ID(l, m, r);

   //set the Loan class private data members
   cout << "Enter the amount of this loan \n";
   cin >> amount;

   cout << "Enter the annual interest rate of this loan (in %) \n";
   cin >> rate;

   cout << "Enter the term (number of months, length of the loan) \n";
   cin >> term;

}

void Loan::display()
{
   //goes to the display from the id class and shows the loan ID
   id.display();

   //display the Loan class private members
   cout << amount << endl;
   cout << rate << endl;
   cout << term << endl;
}

bool operator == (Loan m, Loan n){

//checks if both objects left, middle and right values are the same.
if(m.id.get_left() == n.id.get_left() && m.id.get_middle() == n.id.get_middle() && m.id.get_right() == n.id.get_right()){

    //checks if both objects in Loan mount,rate,term are the same.
    if(m.amount == n.amount && m.rate == n.rate && m.term == n.term)
       return true;
    //if not returns false if both objects in Loan mount,rate,term are NOT the same.
       else{return false;}

}

//returns false if the left, middle and right values are NOT same.
else{return false;}

}
