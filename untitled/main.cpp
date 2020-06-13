#include "main.hpp"
int main(void)
{
    int integer1;
    float float1;
    Student student1;

    integer1=4;
    float1=4.5674;

    student1.setName("Mayank Sharma");
    student1.setId(205119053);
    student1.setDate(2022);

    cout<<"\n-------------Details of student1--------------------\n";
    cout<<"Name: "<<student1.getName()<<"\n";
    cout<<"Student Id: "<<student1.getId()<<"\n";
    cout<<"Student Graduation Year: "<<student1.getGradDate()<<"\n";


    //second way of accesssing the data
    cout<<"------------------------------------------------------";
    cout<<"\nStudent 1: \n";
    student1.print();
    return 0;
}