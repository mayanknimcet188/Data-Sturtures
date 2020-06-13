//
// Created by Mayank Sharma on 10-04-2020.
//

#ifndef QUEUE_QUEUELL_H
#define QUEUE_QUEUELL_H
template <typename T>
class Node {
    T data;
    Node<T> *next;
public:
    Node(T data){
        this->data= data;
        next = NULL;
    }
};

template <typename T>
class QueueLL {
    Node <T> *head;
    Node<T> *tail;
    int size;
public:
    Queue(){
        head = NULL;
        tail = NULL;
        size = 0;
    }
    int getSize() {
    return size;
    }

    bool isEmpty() {
    return size == 0;
    }

    void enqueue(T element){
        Node<T> *newNode = new Node<T>(element);
        if(head == NULL){
            head = newNode;
            tail = newNode;
            size++;
            return;
        }
        tail->next = newNode;
        tail = newNode;
        size++;
    }
    T front() {
        if(isEmpty()){
            cout << "Queue is empty! " << endl;
            return 0;
        }
        return head->data;
    }
    T dequeue() {
        if(isEmpty()){
            cout << "Queue is empty!" << endl;
            return 0;
        }
        Node<T> *temp = head;
        T ans = head->data;
        head = head->next;
        delete temp;
        size--;
        return ans;
    }
};


#endif //QUEUE_QUEUELL_H