// P81a.cpp - This program adds money of two different people
#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;

class AltMoney
{
    public:
        AltMoney();//default constructor
        AltMoney(int d, int c);//constructor with parameters
        void read_money();//initialize AltMoney private members
        friend AltMoney add(AltMoney m1, AltMoney m2, AltMoney &sum);//sums the total of both dollars and cents
        friend AltMoney substract(AltMoney m1, AltMoney m2, AltMoney &sub);//substract the total of both dollars and cents
        void display_money();//shows the value of the dollars and cents entered by the user.
    private:
        int dollars;
        int cents;
};

//

int main()
{
    //AltMoney objects.
    AltMoney m1, m2, sum, sub;

    //initialize both private members value to zero.
    sum = AltMoney(0,0);

    //set m1 member values to the user input.
    m1.read_money();

    //shows m1 money and cents value.
    cout << "The first money is:";
    m1.display_money();

    //set m2 member values to the user input.
    m2.read_money();

    //shows m2 money and cents value.
    cout << "The second money is:";
    m2.display_money();

    //sums m1 and m2 member values and store's it in sum
    add(m1, m2, sum);

    //displays the sum of all dollars and cents.
    cout << "The sum is:";
    sum.display_money();

    //substract m1 and m2 member values and store's it in sub
    substract(m1, m2, sub);
    cout << "The SUBSTRACTION is:";

    //displays the substraction of all dollars and cents.
    sub.display_money();

    return 0;
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

AltMoney add(AltMoney m1, AltMoney m2, AltMoney &sum)
{
    int extra = 0;
    //sums m1 and m2 cents member value.
    sum.cents = m1.cents + m2.cents;

    //checks if the cents sum are 100 or equal.
    if(sum.cents >= 100)
    {
        //substract 100 to cents.
        sum.cents = sum.cents - 100;
        //that 100 or 1 dollar store it in the extra.
        extra = 1;
    }

    //sum the m1 and m2 dollars and the extra to give us the dollar total sum.
    sum.dollars = m1.dollars + m2.dollars + extra;
    return sum;
}

AltMoney substract(AltMoney m1, AltMoney m2, AltMoney &sub)
{

    int extra = 0;

    //substract m1 and m2 cents member value.
    sub.cents = m1.cents - m2.cents;

    //checks if the cents subtracted are of value less than zero.
    if(sub.cents < 0)
    {
        //adds a 100 cents to make the cents value positve.
        sub.cents = sub.cents + 100;
        //sets extra to 1 becouse we added 100 cents to make the value positive.
        extra = 1;
    }

    //substract the m1 and m2 dollars and the extra to give us the dollar total substraction.
    sub.dollars = m1.dollars - m2.dollars - extra;
    return sub;
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
