//
// Created by Mayank Sharma on 09-04-2020.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H


class Stack {
    int *data;
    int nextIndex;
    int capacity;
public:
    Stack() {
        data = new int[4];
        nextIndex  = 0;
        capacity = 4;
    }
    //Return the no of elemnts present in Stack
    int size(){
        return nextIndex;
    }
    bool isEmpty(){
        return nextIndex == 0;
    }
    //insert elemnet
    void push(int element){
        /*if(nextIndex >=capacity) {
            cout << "Stack full" << endl;
            return;
        }*/
        if(nextIndex == capacity){
            int *newData = new int[2*capacity];
            for(int i = 0;i<capacity;i++){
                newData[i] = data[i];
            }
            delete [] data;
            data = newData;
            capacity = capacity*2;
        }
        data[nextIndex++] = element;

    }
    //delete element
    int pop(){
        if(isEmpty()) {
            cout << "Stack is empty" << endl;
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }

    int top(){
        if(isEmpty()){
            cout << "Stack is empty" << endl;
            return INT_MIN;
        }
        return data[nextIndex-1];
    }

};


#endif //STACK_STACK_H
