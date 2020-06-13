#include "main.hpp"

int main()
{
    Student daa[3];
    daa[0].setId(12);
    daa[1].setId(19);
    daa[2].setId(53);

    daa[0].setGrade(0,77);
    daa[1].setGrade(0,97);
    daa[2].setGrade(0,45);

    daa[0].setGrade(1,70);
    daa[1].setGrade(1,90);
    daa[2].setGrade(1,44);

    daa[0].setGrade(2,72);
    daa[1].setGrade(2,93);
    daa[2].setGrade(2,43);

    for(int i=0;i<3;i++)
    {
        daa[i].printInfo();
        cout<<"\n\n";
    }
    return 0;
}