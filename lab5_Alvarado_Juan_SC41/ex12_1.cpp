//Juan Alvarado Caraballo
//S01035309

#include <iostream>


using namespace std;

class Area
{
    public:
        Area();
        void setArea(int ta);//sets area
        float getArea();//gets area
        void setUnits(string u);//sets the units
        string getUnits();//gets the units


    private:
       float area_value;//stores the area value given by the user
       string units;//stores the units string given by the user
};

int main()
{

    //creates dynamic variable
    Area* p1 = new Area();

    float tempArea;
    string tempUnit;

    //ask the user for the units
    cout << "Enter the units:";
    cin >> tempUnit;

    //sets tempUnits to p1
    p1->setUnits(tempUnit);

    //ask the user for the area
    cout << "Enter the area value: ";
    cin >> tempArea;

    //sets TempArea to p1
    p1->setArea(tempArea);

    //return the pointer object and divides by /2 and /4
    cout << "A half of your area is = " << p1->getArea()/2 << p1->getUnits() << endl;
    cout << "A quarter of your area is = " << p1->getArea()/4 << p1->getUnits() << endl;

    //after the program is done destroy the dynamic variable p1
    delete p1;

    return 0;

}

Area::Area()
{

}


void Area::setArea(int av){
area_value = av;

}

float Area::getArea(){
    return area_value;
}

void Area:: setUnits(string u){units = u;}


string Area::getUnits(){return units;}




