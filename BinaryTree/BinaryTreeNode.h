//
// Created by Mayank Sharma on 12-04-2020.
//

#ifndef BINARYTREE_BINARYTREENODE_H
#define BINARYTREE_BINARYTREENODE_H

template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    BinaryTreeNode(T data){
        this->data = data;
        left  =NULL;
        right = NULL;
    }
    ~BinaryTreeNode(){
        delete left;
        delete right;
    }
};


#endif //BINARYTREE_BINARYTREENODE_H
