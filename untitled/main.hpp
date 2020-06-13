#include<iostream>
using namespace std;
class Student
{
    string name;
    int id;
    int gradDate;
public:
    void setName(string nameIn);
    void setId(int idIn);
    void setDate(int dateIn);
    string getName();
    int getId();
    int getGradDate();
    void print();
};

void Student::setName(string nameIn)
{
    name=nameIn;
}
void Student::setId(int idIn)
{
    id = idIn;
}
void Student:: setDate(int dateIn)
{
    gradDate=dateIn;
}
string Student::getName()
{
    return name;
}
int Student::getId()
{
    return id;
}
int Student::getGradDate()
{
    return gradDate;
}
void Student::print()
{
    cout<<name<<" "<<id<<" "<<gradDate;
}