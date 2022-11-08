//tells the compiler that if the class has been define once do not define it again.
#ifndef ID_H
#define ID_H

#include<iostream>
class ID
{
    public:
        ID( );
        ID(int, int, int);
        void display();
    private:
        int left;
        int middle;
        int right;
};

//tells the compiler this is the end of the defined class.
#endif // ID_H
