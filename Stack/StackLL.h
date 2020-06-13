//
// Created by Mayank Sharma on 09-04-2020.
//

#ifndef STACK_STACKLL_H
#define STACK_STACKLL_H
template <typename T>
class Node {
public:
    T data;
    Node<T> *next;
    Node(T data) {
        this->data = data;
        next = NULL;
    }
};
template <typename T>
class StackLL {
    Node<T> *head;
    int size; //number of elements present in stack
public:
    StackLL() {
        head = NULL;
        size = 0;
    }
    int getSize() {
        return size;
    }
    bool isEmpty(){
        return size == 0;
    }

    void push(T element){
        Node<T> *newNode = new Node<T>(element);
        newNode->next = head;
        head = newNode;
        size++;
    }
    T pop() {
        if(isEmpty()) {
            cout << "Stack is empty" << endl;
            return 0;
        }
        T ans = head->data;
        Node<T> *temp = head;
        head = head->next;
        size--;
        delete temp;
        return ans;
    }
    T top() {
        if(head == NULL){
            cout << "Stack is empty" << endl;
        }
        return head->data;
    }
};


#endif //STACK_STACKLL_H
