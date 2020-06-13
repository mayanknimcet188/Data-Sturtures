#include <iostream>
using namespace std;
#include "TreeNode.h"
#include<queue>
TreeNode<int>* takeInput() {
    int rootData;
    cout << "Enter Data: "<< endl;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    int n;
    cout << "Enter the num of children of " <<rootData << endl;
    cin >> n;
    for(int i = 0;i < n; i++){
        TreeNode<int>*child = takeInput();
        root->children.push_back(child);
    }
    return root;
}
TreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout << "Enter root data: " << endl;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cout << "Enter the num of children of " << front->data << endl;
        cin >> numChild;
        for(int i = 0;i<numChild;i++){
            int childData;
            cout<<"Enter " << i << "th child of " << front->data << endl;
            cin>>childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}
void printLevelWise(TreeNode<int>* root){
    if(root == NULL) return;
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << ":" ;
        for(int i = 0; i < front->children.size(); i++){
            cout<< front->children[i]->data <<",";
            pendingNodes.push(front->children[i]);
        }
        cout << endl;
    }
}

int numNodes(TreeNode<int>* root){
    if(root == NULL) return 0;
    int ans = 1;
    for(int i = 0; i < root->children.size(); i++){
        ans+=numNodes(root->children[i]);
    }
    return ans;
}
void printTree(TreeNode<int>* root){
    if(root == NULL) return; //edge case NOT a base case
    cout << root->data << ":";
    for(int i = 0;i<root->children.size();i++){
        cout << root->children[i]->data << ",";
    }
    cout << endl;
    for(int i = 0;i<root->children.size() ; i++){
        printTree(root->children[i]);
    }
}

void printAtLevelK(TreeNode<int>* root,int k){
    if(root == NULL) return;
    if(k == 0) {
        cout << root->data << endl;
    }
    for(int i = 0;i<root->children.size();i++){
        printAtLevelK(root->children[i],k-1);
    }
}
void preOrder(TreeNode<int>* root){
    if(root == NULL) return;
    cout << root->data << " ";
    for(int i = 0;i<root->children.size();i++){
        preOrder(root->children[i]);
    }
}
void postOrder(TreeNode<int>* root){
    if(root ==NULL) return;
    for(int i = 0;i<root->children.size();i++){
        postOrder(root->children[i]);
    }
    cout << root->data << " ";
}
void deleteTree(TreeNode<int>* root){
    for(int i = 0;i < root->children.size();i++){
        deleteTree(root->children[i]);
    }
    delete root;
}
TreeNode<int>* removeLeafNodes(TreeNode<int>* root){
    if(root == NULL) return NULL;
    if(root->children.size() == 0) delete root;
    for(int i = 0;i<root->children.size();i++){
        removeLeafNodes(root->children[i]);
    }
    if(root!=NULL) return root;
    else return NULL;
}
// 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
int main() {
   /* TreeNode<int>* root = new TreeNode<int>(1);
    TreeNode<int>* node1 = new TreeNode<int>(2);
    TreeNode<int>* node2 = new TreeNode<int>(3);
    TreeNode<int>* node3 = new TreeNode<int>(4);
    root->children.push_back(node1);
    root->children.push_back(node2);*/
    TreeNode<int>* root = takeInputLevelWise();
    printTree(root);
    cout << "num: " <<numNodes(root) << endl;
    cout << "level 2: " << endl;
    printAtLevelK(root,2);
    printLevelWise(root);
    preOrder(root);
    postOrder(root);
    //deleteTree(root);
    root = removeLeafNodes(root);
    printLevelWise(root);
    //delete root;
}
