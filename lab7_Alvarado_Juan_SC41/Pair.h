#ifndef PAIR_H
#define PAIR_H
#include <iostream>

using namespace std;

// Class for a pair of values of type T:
 template<class T>
 class Pair
 {

        public:
        Pair();//default constructor
        void set_element(int position, T value); //sets position and the value or name of the student.

        //returns the value or name depending on the position.
        T get_element(int);

        void display_pairs(); //display the info stored in first and second value

        private:
        T first;//stores the value of the first pair
        T second;//stores the value of the second pair
 };

template<class T>
 Pair<T>::Pair()
 {
 // empty body
 }


template<class T>
 void Pair<T>::set_element(int position, T value)
 {
 if (position == 1)
 first = value;
 else if (position == 2)
 second = value;
  else
 {
 cout << "Error: Illegal pair position. \n";
 exit(1);
 }
 }



 template<class T>
T Pair<T>::get_element(int position){
if(position == 1)
return first;
else
    return second;
 }


 template <class T>
 void Pair<T>::display_pairs(){


 cout <<first << " " << second << endl;

 }




#endif // PAIR_H
