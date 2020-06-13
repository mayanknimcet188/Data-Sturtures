#include <iostream>
#include "Node.h"
using namespace std;
void print(Node *head) {
    Node *temp = head;
    while(temp != NULL){
        cout << temp->data<<" ";
        temp = temp->next;
    }
}

Node* takeInput() {
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL){ head = newNode;tail = newNode;}
        else {
           tail->next = newNode;
           tail = tail->next;
        }
        cin >> data;
    }
    return head;
}

Node* insertNode(Node *head,int i,int data){
    Node *newNode = new Node(data);
    int count = 0;
    Node *temp = head;
    if(i == 0) {
        newNode->next = head;
        head = newNode;
        return head;
    }
    while(temp!=NULL && count <i-1){
       temp = temp->next;
       count++;
    }
    if(temp!=NULL) {
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return head;
}
Node* deleteNode(Node *head,int i){
    Node *temp = head;
    int count =0;
    Node *a;
    if(i == 0){
        a = head;
        head = head->next;
        delete a;
        return head;
    }
    while(temp!=NULL && count < i-1){
        temp = temp->next;
        count++;
    }
    if(temp!=NULL) {
        a = temp->next;
        temp->next = temp->next->next;
        delete a;
    }
    return head;


}
int main() {

    Node *head = takeInput();
    print(head);
    int i,data;
    cin >> i>>data;
    head = insertNode(head,i,data);
    print(head);
    //Statically
    /*Node n1(1);
    Node *head = &n1;
    Node n2(2);
    Node n3(3);
    Node n4(4);
    Node n5(5);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    print(head);*/
    return 0;
}
