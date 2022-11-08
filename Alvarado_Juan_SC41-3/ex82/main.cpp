// P82.cpp - This program adds money of two different people
#include<iostream>
#include<cstdlib>
#include "altmoney.h"
using namespace std;

int main()
{

    //AltMoney objects.
    AltMoney m1, m2, sum, sub;


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
    sum = m1 + m2;

    //displays the sum of all dollars and cents.
    cout << "The sum is:";
    sum.display_money();

    //substract m1 and m2 member values and store's it in sub
    sub = m1 - m2;
    cout << "The substraction is:";

    //displays the substraction of all dollars and cents.
    sub.display_money();

    //overloading the == symbol
    if (m1 == m2) {
        m1.display_money();
        cout << " is equal to ";
        m2.display_money();
        cout << endl;
    }
    //overloading the > symbol
    else if (m1 > m2) {
        m1.display_money();
        cout << " is greater than ";
        m2.display_money();
        cout << endl;
    }
    //overloading the < symbol
    else if(m1 < m2) {
        m1.display_money();
        cout << " is lesser than ";
        m2.display_money();
        cout << endl;
    }

    else
    cout << "Invalid option" << endl;

    return 0;
}



