//
// Created by Mayank Sharma on 04-04-2020.
//

#ifndef POLYNOMIAL_POLYNOMIAL_H
#define POLYNOMIAL_POLYNOMIAL_H


class polynomial {
    int *degCoeff;
    int capacity;

public:
    //default constructor
    polynomial(){
        degCoeff = new int[10];
        capacity = 10;
        for(int i=0;i<capacity;i++){
            degCoeff[i] = 0;
        }
    }
    //copy constructor
    polynomial(polynomial  const &p){
        this->degCoeff = new int[p.capacity];
        for(int i=0;i<p.capacity;i++){
            this->degCoeff[i] = p.degCoeff[i];
        }
        this->capacity = p.capacity;
    }
    //copy assignment operator
    void operator=(polynomial const &p){
        this->degCoeff = new int[p.capacity];
        for(int i=0;i<p.capacity;i++){
            this->degCoeff[i] = p.degCoeff[i];
        }
        this->capacity = p.capacity;
    }
    // setCoefficient
    void setCoefficient(int degree,int coefficent){
        if(degree<capacity){
            degCoeff[degree] = coefficent;
        }
        else{
            while(degree>=capacity){
                int *newDegCoeff = new int[2*capacity];
                for(int i=0;i<capacity;i++){
                    newDegCoeff[i] = degCoeff[i];
                }
                for(int i=capacity;i<2*capacity;i++){
                    newDegCoeff[i] = 0;
                }
                delete [] degCoeff;
                degCoeff = newDegCoeff;
                capacity *=2;
            }
            degCoeff[degree] = coefficent;
        }
    }
    //overloading

    //+
    polynomial operator+(polynomial const &p) {
        polynomial newPoly;
        int newCapacity = (this->capacity<p.capacity)?this->capacity:p.capacity;
        int i=0;
        for(;i<newCapacity;i++){
            newPoly.setCoefficient(i,degCoeff[i]+p.degCoeff[i]);
        }
        if(i<this->capacity){
            while(i<this->capacity){
                newPoly.setCoefficient(i,degCoeff[i]);
                i++;
            }
        }
        else if(i<p.capacity) {
            while (i < p.capacity) {
                newPoly.setCoefficient(i, p.degCoeff[i]);
                i++;
            }
        }
        return newPoly;
    }
    //-
    polynomial operator-(polynomial const &p) {
        polynomial newPoly;
        int newCapacity = (this->capacity<p.capacity)?this->capacity:p.capacity;
        int i=0;
        for(;i<newCapacity;i++){
            newPoly.setCoefficient(i,degCoeff[i]-p.degCoeff[i]);
        }
        if(i<this->capacity){
            while(i<this->capacity){
                newPoly.setCoefficient(i,degCoeff[i]);
                i++;
            }
        }
        else if(i<p.capacity) {
            while (i < p.capacity) {
                newPoly.setCoefficient(i, -p.degCoeff[i]);
                i++;
            }
        }
        return newPoly;

    }
    //*
    polynomial operator*(polynomial const &p) {
        polynomial newPoly;
        for(int i =0 ;i < this->capacity;i++){
            for(int j=0;j<p.capacity;j++){
                newPoly.setCoefficient(i+j,(this->degCoeff[i]+p.degCoeff[j]));
            }
        }
       return newPoly;
    }
    //print
    void print() const {
        for(int i=0;i<capacity;i++){
            if(degCoeff[i]!=0){
                cout << degCoeff[i]<<"x"<<i<<" ";
            }
        }
    }
};


#endif //POLYNOMIAL_POLYNOMIAL_H
