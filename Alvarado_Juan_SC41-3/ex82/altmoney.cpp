#include "altmoney.h"
#include<iostream>
#include<cstdlib>
using namespace std;


bool operator > (AltMoney m1, AltMoney m2)
{

//checks if m1 dollars is greater than m2 dollars
if(m1.dollars > m2.dollars)
    return true;

//returns false otherwise
else
    return false;
 }


 bool operator < (AltMoney m1, AltMoney m2)
{

//only checks if m1 dollars is less than m2 dollars
if(m1.dollars < m2.dollars)
    return true;

//if not returns false
else
    return false;

}

bool operator == (AltMoney m1, AltMoney m2)
{

//checks to see if the amount of dollars and cents are the same
if(m2.dollars == m1.dollars && m2.cents == m1.cents)
     return true;

     //if not returns false
     else
        return false;

}

AltMoney operator +(AltMoney m1, AltMoney m2)
{
     AltMoney temp;
     int extra = 0;

     //sum cents
     temp.cents = m1.cents + m2.cents;

     //if cents is bigger than 100 go here
     if(temp.cents >=100){

         //subtract 100 and set the total to cents
         temp.cents = temp.cents - 100;

         //that 100 subtracted is now a dollar
         extra = 1;
      }

      //sums the total amount of dollars
      temp.dollars = m1.dollars + m2.dollars + extra;

      return temp;
}

AltMoney operator -(AltMoney m1, AltMoney m2)
{

    int extra = 0;
	AltMoney sub;
	//subtract cents
	sub.cents = m1.cents - m2.cents;

	//if cents is bigger than 100 go here
	if (sub.cents >= 100) {
        //subtract 100 and set the total to cents
		sub.cents = sub.cents - 100;

        //that 100 subtracted is now a dollar
		extra = 1;

		//sums the total of dollars
		sub.dollars = m1.dollars - m2.dollars - extra;
	}

	//if cents are negative go here
	else if (sub.cents <=-1){

	    //makes cents positive number (cant be negative)
        sub.cents = abs(sub.cents);

        //sums the total dollars
        sub.dollars = m1.dollars - m2.dollars;

	}

	//if the cents are positive but less than 100 go here.
	else{

        //sum the total dollars
		sub.dollars = m1.dollars - m2.dollars;
    }


	return sub;
}



AltMoney::AltMoney()
{
}
AltMoney::AltMoney(int d, int c)
{
       dollars = d;
       cents = c;
}

void AltMoney::display_money()
{
     cout << "$" << dollars << ".";
     if(cents <= 9)
         cout << "0";  //to display a 0 in the left for numbers less than 10
     cout << cents << endl;
}

void AltMoney:: read_money()
{

    //user inputs dollar
    cout << "Enter dollar \n";
    cin >> dollars;

    //user inputs cents
    cout << "Enter cents \n";
    cin >> cents;


    //check if dollar or cents is a negative value.
    if( dollars < 0 || cents < 0)
    {
        //display a error message and terminates program.
        cout << "Invalid dollars and cents, negative values\n";
        exit(1);
    }
}
