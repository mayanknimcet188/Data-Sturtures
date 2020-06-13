#include<iostream>
#include<iomanip>
using namespace std;

class Student
{
    int grade[3];
    int id;
public:
    Student();
    void setId(int idIn);
    void setGrade(int index,int gradeIn);
    int getId();
    int getGrade(int index);
    int getAvg();
    void printInfo();
};

//Definitions
Student::Student()
{
    for(int i=0;i<3;i++)
{
        grade[i]=0;
}
    id=0;
}
void Student::setId(int idIn)
{
    id=idIn;
}
void Student::setGrade(int index, int gradeIn)
{
    grade[index]=gradeIn;
}
int Student::getId() {
    return id;
}
int Student::getGrade(int index) {
    return grade[index];
}
int Student:: getAvg() {
    int sum;
    for(int i=0;i<3;i++)
    {
        sum = sum + grade[i];
    }
    return sum/3.0;
}
void Student:: printInfo() {
    for(int i=0;i<3;i++)
    {
        cout<<grade[i]<<" ";
    }
    cout<<"\n "<<id;
}