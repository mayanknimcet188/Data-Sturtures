//
// Created by Mayank Sharma on 09-04-2020.
//

#ifndef STACK_STACKTEMPLATE_H
#define STACK_STACKTEMPLATE_H

template <typename T>
class StackTemplate {
   T *data;
   int nextIndex;
   int capacity;
public:
    StackTemplate(){
        data = new T[5];
        nextIndex = 0;
        capacity = 5;
    }

    int size(){
        return nextIndex;
    }
    bool isEmpty(){
        return nextIndex == 0;
    }
    void push(T element){
        if(nextIndex == capacity){
            T *newData = new T[2*capacity];
            for(int i = 0;i<capacity;i++){
                newData[i] = data[i];
            }
            delete [] data;
            data = newData;
            capacity*=2;
        }
        data[nextIndex++] =element;
    }
    T pop(){
        if(isEmpty()) {
            cout << "Stack empty" << endl;
            return 0; //if we use template as return type use 0 as standard return value for errors
        }
        nextIndex--;
        return data[nextIndex];
    }
    T top(){
        if(isEmpty()){
            cout << "Stack empty" << endl;
            return 0;
        }
        return data[nextIndex-1];
    }
};




#endif //STACK_STACKTEMPLATE_H
