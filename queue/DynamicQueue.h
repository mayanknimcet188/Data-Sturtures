//
// Created by Mayank Sharma on 09-04-2020.
//

#ifndef QUEUE_DYNAMICQUEUE_H
#define QUEUE_DYNAMICQUEUE_H

template <typename T>
class DynamicQueue {
    T *data;
    int firstIndex;
    int nextIndex;
    int size;
    int capacity;
public:
    DynamicQueue(int s){
        data = new T[s];
        firstIndex = -1;
        nextIndex = 0;
        size = 0;
        capacity = s;
    }
    int getSize(){
        return size;
    }
    bool isEmpty(){
        return size == 0;
    }
    void enqueue(T element){
        if(size == capacity){
            T *newData = new T[2*capacity];
            int j = 0;
            for(int i = firstIndex;i<capacity;i++){
                newData[j++] = data[i];
            }
            for(int i =0;i<firstIndex;i++) {
                newData[j++] = data[i];
            }
            delete [] data;
            data = newData;
            firstIndex = 0;
            nextIndex = capacity;
            capacity *=2;
        }
        data[nextIndex] = element;
        nextIndex = (nextIndex + 1) % capacity;
        if(firstIndex == -1) firstIndex == 0;
        size++;
    }
    T front(){
        if(isEmpty()) {
        cout << "Queue empty" << endl;
        return 0;
    }
        return data[frontIndex];
    }
    T dequeue(){
        if(isEmpty()){
            cout << "Queue is empty"<< endl;
            return 0;
        }
        T ans = data[firstIndex];
        firstIndex++;
        size--;
        if(size == 0){
            firstIndex =-1;
            nextIndex = 0;
        }
        return ans;
    }
};


#endif //QUEUE_DYNAMICQUEUE_H
