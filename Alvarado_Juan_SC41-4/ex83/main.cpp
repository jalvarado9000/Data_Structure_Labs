// P83.cpp - This program adds money of two different people
// It reads the amounts for two people from an
// input file in_file.dat and writes the result into a file out_file.dat

#include<iostream>
#include<cstdlib>
#include<fstream>
using namespace std;

class AltMoney
{
    public:
        AltMoney();
        friend istream& operator >> (istream& ins, AltMoney& m);//operation overloading the >> symbol
        friend ostream& operator << (ostream& ous, const AltMoney& m);//operation overloading the << symbol
        friend AltMoney operator +(AltMoney m1, AltMoney m2);//operation overloading the + symbol

    private:
        int dollars;//stores the value of the dollars
        int cents;//stores the value of cents
};

//prototype function.
void get_streams(ifstream& ins, ofstream& ous);


int main()
{
    ifstream ins;
    ofstream ous;
    AltMoney m1, m2, sum;


    //checks if the file with value is created before running code.
    get_streams(ins, ous);

    //creates the m1 object.
    ins >> m1;
    ous << "The first money is:";

    //prints the m1 data member values.
    ous << m1;

    //creates the m2 object.
    ins >> m2;
    ous << "The second money is:";
    //prints the m1 data member values.
    ous << m2;

    //sum the m1 and m2 values and store it in the sum object.
    sum = m1 + m2;
    //prints the sum value.
    ous << "The sum is:";
    ous << sum << endl;


    //closes the file before the program ends.
    ins.close();
    ous.close();

    return 0;
}

AltMoney::AltMoney()
{
}


ostream& operator <<(ostream& ous,const AltMoney& m)
{
    //prints to the dat file the dollars
    ous << "$" << m.dollars << ".";

    //checks if cents is less than 9
    if (m.cents <= 9)
        ous << "0";  //to display a 0 on the left for numbers less than 10

    //prints to the dat file the cents
    ous << m.cents << endl;
    return ous;
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


istream& operator >>(istream& ins, AltMoney& m)
{
    //create temporary values to store dollar and cent values.
    int d, c;

    //input for d and c
    ins >> d;
    ins >> c;

    //checks if d and c are negative values
    if (d < 0 || c < 0)
    {
        cout << "Invalid dollars and cents, negative values\n";
        exit(1);
    }
    //assigns d and c to the dollar and cents members.
    m.dollars = d;
    m.cents = c;
    return ins;
}

//checks and creates if files exist
void get_streams(ifstream& ins, ofstream& ous)
{
    //looks in the project directory if the file is created
    ins.open("in_file.dat");

    //otherwise it terminates the program and displays the error message.
    if (ins.fail())
    {
       cout << "Failed to open the input file. \n";
       exit(1);
    }

    //creates the output file where the output will be store.
    ous.open("out_file.dat");

    //otherwise it terminates the program and displays the error message.
    if (ous.fail())
    {
       cout << "Failed to open the output file. \n";
       exit(1);
    }
}
