//Juan M. Alvarado Caraballo
//S01035309
//Fecha de Entrega: 10/26/2020
#include <iostream>
#include "pair.h"

using namespace std;

int main()
{

//class template object with type int parameter
Pair <int> grades;
//sets the position and grade of the student
grades.set_element(1,87);
grades.set_element(2,90);

//class template object with type string parameter
Pair <string> names;
//sets the position and name of the student
names.set_element(1,"Martha");
names.set_element(2,"Tom");


//displays the pairs of scores
grades.display_pairs();
// display the name pairs
names.display_pairs();

    return 0;
}
