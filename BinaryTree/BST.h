//
// Created by Mayank Sharma on 14-04-2020.
//

#ifndef BINARYTREE_BST_H
#define BINARYTREE_BST_H

#include "BinaryTreeNode.h"
class BST {
    BinaryTreeNode<int>* root;
private:
    bool hasData(int data,BinaryTreeNode<int>*node) {
        if(node == NULL) {
            return false;
        }
        if(node->data == data) return true;
        else if(data < node->data) {
            return hasData(data,node->left);
        }
        else{
            return hasData(data,node->right);
        }
    }
    BinaryTreeNode<int>* insert(int data,BinaryTreeNode<int>* node){
        if(node == NULL){
            BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(data);
            return newNode;
        }
        if(node->data > data) {
            node->left = insert(data,node->left);
            return node;
        }
        else if(node->data < data) {
            node->right = insert(data,node->right);
            return node;
        }
    }
    BinaryTreeNode<int>* deleteNode(int data,BinaryTreeNode<int>* node){
        if(node == NULL) return NULL;
        if(data > node->data){
            node->right = deleteNode(data,node->right);
            return node;
        }
        else if(data < node->data){
            node->left = deleteNode(data,node->left);
            return node;
        }
        else {
            if(node->left == NULL && node->right == NULL){
                delete node;
                return NULL;
            }
            else if(node->left!=NULL && node->right == NULL){
                BinaryTreeNode<int>* temp = node->left;
                node->left = NULL;
                delete node;
                return temp;
            }
            else if(node->left==NULL && node->right != NULL){
                BinaryTreeNode<int>* temp = node->right;
                node->right = NULL;
                delete node;
                return temp;
            }
            else if(node->left!=NULL && node->right!=NULL){
                BinaryTreeNode<int>* smallRight = node->right;
                while(smallRight->left!=NULL){
                    smallRight = smallRight->left;
                }
                node->data = smallRight->data;
                node->right = deleteData(smallRight->data,node->right);
                return node;
            }


        }
    }
    void printTree(BinaryTreeNode<int>* root) {
        if(root == NULL) return;
        cout <<root->data<<":";
        if(root->left != NULL) cout<<"L:"<<root->left->data<<" ";
        if(root->right!=NULL) cout<<"R:"<<root->right->data;
        cout<<endl;
        printTree(root->left);
        printTree(root->right);
    }
public:
    BST() {
        root = NULL;
    }
    ~BST() {
        delete root;
    }
    void deleteData(int data) {

    }
    void insert(int data){
        root = insert(data,root);

    }
    bool hasData(int data) {
        return hasData(data,root);
    }
    void printTree() {
        printTree(root);
    }
};


#endif //BINARYTREE_BST_H
