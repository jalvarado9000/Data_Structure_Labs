//Juan M. Alvarado Caraballo
//S01035309

#include <iostream>


using namespace std;


class Student
{
    public:
        Student();
        void set_arr();//set array private members
        //getters
        string get_idnumber();
        string get_name();



    private:
    string student_name;
    string student_idnumber;


};

int main()
{
    int student_number;


    //ask the user for the size that will be the dynamic array
    cout << "How many students are in the data base" << endl;
    cin >> student_number;


    //creates a dynamic array class with the size student_number
    Student* data_base = new Student[student_number]();


    //ask user to fill in the dynamic array
    for(int i = 0; i < student_number; i++){

        data_base[i].set_arr();
    }



    //Prints out the contents of the array in table form.

    cout << "\n\nStudent Name:\t" << "Student Id Number:" << endl;

    for(int i = 0; i < student_number; i++){

        cout <<data_base[i].get_name() << "\t\t" << data_base[i].get_idnumber() << endl;

    }



    //deletes all of the dynamic class array content
    delete[] data_base;



    return 0;
}

Student::Student()
{

}


void Student::set_arr(){

//ask user for the contents to fill the array
cout << "Enter the students name" << endl;
cin >> student_name;
cout << "Enter the student id number" << endl;
cin >> student_idnumber;
}

//gets content for the array
string Student::get_idnumber(){return student_idnumber;}
string Student::get_name(){return student_name;}

