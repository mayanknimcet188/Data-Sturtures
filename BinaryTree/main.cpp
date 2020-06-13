#include <iostream>
#include "BinaryTreeNode.h"
#include<algorithm>
using namespace std;
#include<queue>
void printTree(BinaryTreeNode<int>* root) {
    if(root == NULL) return;
    cout <<root->data<<":";
    if(root->left != NULL) cout<<"L:"<<root->left->data<<" ";
    if(root->right!=NULL) cout<<"R:"<<root->right->data;
    cout<<endl;
    printTree(root->left);
    printTree(root->right);
}

BinaryTreeNode<int>* takeInput(){
    int rootData;
    cout << "Enter data" << endl;
    cin >> rootData;
    if(rootData == -1) return NULL;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int>* leftChild = takeInput();
    BinaryTreeNode<int>* rightChild = takeInput();
    root->left = leftChild;
    root->right = rightChild;
    return root;
}

BinaryTreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout << "Enter data" << endl;
    cin >> rootData;
    if(rootData == -1) return NULL;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter left child of " << front->data << endl;
        int leftChildData;
        cin >> leftChildData;
        if(leftChildData != -1){
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftChildData);
            front->left = child;
            pendingNodes.push(child);
        }

        cout << "Enter right child of " << front->data << endl;
        int rightChildData;
        cin >> rightChildData;
        if(rightChildData != -1){
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightChildData);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}

void printLevelWise(BinaryTreeNode<int>* root){
    if(root == NULL) return;
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    //cout<< root->data <<" ";
    while(pendingNodes.size()!=0){
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data <<":";
        if(front->left!=NULL) cout << "L: "<<front->left->data<<" ";
        if(front->right!=NULL) cout << "R: "<<front->right->data;
        cout<<endl;
        if(front->left!=NULL)pendingNodes.push(front->left);
        if(front->right!=NULL)pendingNodes.push(front->right);
    }
}

int numNodes(BinaryTreeNode<int>* root) {
    if(root == NULL) return 0;
    return 1+numNodes(root->left)+numNodes(root->right);
}

void inorder(BinaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->data <<" ";
    inorder(root->right);
}

int height(BinaryTreeNode<int>* root){
    if(root == NULL) return 0;
    return 1+max(height(root->left),height(root->right));
}

int diameter(BinaryTreeNode<int>* root){
    if(root == NULL) {
        return 0;
    }

    int option1 = height(root->left) + height(root->right);
    int option2 = diameter(root->left);
    int option3 = diameter(root->right);
    return max(option1,max(option2,option3));
}

pair<int,int> heightDiameter(BinaryTreeNode<int>* root){
    if(root == NULL) {
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }
    pair<int, int> leftAns = heightDiameter(root->left);
    pair<int, int> rightAns = heightDiameter(root->right);
    int ld = leftAns.second;
    int lh = leftAns.first;
    int rd = rightAns.second;
    int rh = rightAns.first;

    int height = 1+max(lh,rh);
    int diameter = max(lh+rh,max(ld,rd));
    pair<int,int> p;
    p.first = height;
    p.second = diameter;
    return p;
}
vector<int>* getRootToNodePath(BinaryTreeNode<int>* root,int data){
    if(root == NULL) {
        return NULL;
    }
    if(root->data == data) {
        vector<int>* output = new vector<int>();
        output->push_back(root->data);
        return output;
    }
    vector<int>* leftOutput = getRootToNodePath(root->left,data);
    if(leftOutput!=NULL) {
        leftOutput->push_back(root->data);
        return leftOutput;
    }

    vector<int>* rightOutput = getRootToNodePath(root->right,data);
    if(rightOutput!=NULL) {
        rightOutput->push_back(root->data);
        return rightOutput;
    } else return NULL;
}



// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main() {
    /*BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
    BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(2);
    BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(3);
    root->left = node1;
    root->right = node2;*/
    BinaryTreeNode<int>* root = takeInputLevelWise();
    /*printLevelWise(root);
    inorder(root);
    cout<<endl;
    cout << "Num: "<<numNodes(root)<<endl;
    pair<int,int> p = heightDiameter(root);
    cout<< "Height: " << p.first << endl;
    cout << "Diameter: " << p.second << endl;*/

    vector<int>* output = getRootToNodePath(root,8);
    for(int i = 0; i < output->size();i++){
        cout << output->at(i) << endl;
    }
    delete output;
    return 0;
}
