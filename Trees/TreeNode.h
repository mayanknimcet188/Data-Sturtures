//
// Created by Mayank Sharma on 10-04-2020.
//

#ifndef TREES_TREENODE_H
#define TREES_TREENODE_H
#include<vector>
using namespace std;
template <typename T>
class TreeNode {
public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data){
        this->data = data;
    }

    ~TreeNode() {
        for(int i = 0;i < children.size();i++){
            delete children[i];
        }
    }
};


#endif //TREES_TREENODE_H
