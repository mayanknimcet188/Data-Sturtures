//
// Created by Mayank Sharma on 05-04-2020.
//

#ifndef LINKEDLIST_NODE_H
#define LINKEDLIST_NODE_H


class Node {
public:
    int data;
    Node *next;;
    Node(int data){
        this->data = data;
        next = NULL;
    }
};


#endif //LINKEDLIST_NODE_H
