#include <iostream>
using namespace std;
#include "polynomial.h"
int main() {
    polynomial p1,p2;
    p1.setCoefficient(2,3);
    p1.setCoefficient(3,6);
    p1.setCoefficient(7,2);
    p2.setCoefficient(2,2);
    p2.setCoefficient(4,4);
    p2.setCoefficient(10,2);
    polynomial p3,p4,p5;
    p3 = p1+p2;
    p4 = p1*p2;
    p5 = p1-p2;
    p1.print();
    cout << endl;
    p2.print();
    cout << endl;
    p3.print();
    cout << endl;
    p4.print();
    cout << endl;
    p5.print();
    cout << endl;
    return 0;
}
