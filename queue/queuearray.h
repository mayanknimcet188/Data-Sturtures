//
// Created by Mayank Sharma on 09-04-2020.
//

#ifndef QUEUE_QUEUEARRAY_H
#define QUEUE_QUEUEARRAY_H

template <typename T>
class queuearray {
    T *data;
    int firstIndex;
    int nextIndex;
    int size;
    int capacity;
public:
    queuearray(int s){
        data = new T[s];
        nextIndex = 0;
        firstIndex = -1;
        size = 0;
        capacity = s;
    }
    int getSize() {
        return size;
    }
    bool isEmpty(){
        return size == 0;
    }

    //insert element
    void enqueue(T element){
        if(size == capacity){
            cout << "Queue Full ! " << endl;
            return;
        }
        data[nextIndex] = element;
        nextIndex = (nextIndex+1) % capacity;
        if(firstIndex == -1) firstIndex = 0;
        size++;
    }
    T front() {
        if(isEmpty()) {
            cout << "Queue is empty ! " << endl;
            return 0;
        }
        return data[firstIndex];
    }
    T dequeue(){
        if(isEmpty()){
            cout << "Queue empty!" << endl;
            return 0;
        }
        T ans = data[firstIndex];
        firstIndex = (firstIndex + 1) % capacity;
        size--;
        if(size == 0){
            firstIndex = -1;
            nextIndex = 0;
        }
        return ans;
    }
};


#endif //QUEUE_QUEUEARRAY_H
