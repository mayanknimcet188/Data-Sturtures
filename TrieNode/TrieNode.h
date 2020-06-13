//
// Created by Mayank Sharma on 19-04-2020.
//

#ifndef TRIENODE_TRIENODE_H
#define TRIENODE_TRIENODE_H
#include<string>
using namespace std;
class TrieNode {
public:
    char data;
    TrieNode** children;
    bool isTerminal;

    TrieNode(char data){
        this->data = data;
        children = new TrieNode*[26];
        for(int i = 0; i < 26;i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    TrieNode *root;
private:
    void insertWord(TrieNode* root,string word){
        if(word.length() == 0){
            root-> isTerminal = true;
            return;
        }
        //Small calc
        int index = word[0] - 'a';
        TrieNode* child;
        if(root->children[index] == NULL){
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        else{
            child = root->children[index];
        }
        //Recursive call
        insertWord(child,word.substr(1));
    }
    bool search(TrieNode* root,string word){
        if(word.size() == 0) {
            if(root->isTerminal) return true;
            else return false;
        }
        int index = word[0] - 'a';
        if(root->children[index] != NULL){
            TrieNode* child = root->children[index];
            return search(child,word.substr(1));
        }
        else return false;
    }
    void deleteWord(TrieNode* root,string word){
        if(word.size() == 0) {
            root->isTerminal = false;
            return;
        }
        int index = word[0] - 'a';
        TrieNode* child;
        if(root->children[index] == NULL) return;
        else{
             child = root->children[index];
            deleteWord(child,word.substr(1));
        }
        if(child ->isTerminal == false) {
            for(int i=0;i<26;i++){
                if(child->children[i]!=NULL) return;
            }
            delete child;
            root->children[index] = NULL;
        }
    }
public:
    Trie() {
        root = new TrieNode('\0');
    }

    void insertWord(string word){
        insertWord(root,word);
    }
    bool search(string word){
        return search(root,word);
    }
    void deleteWord(string word){
        deleteWord(root,word);
    }

};


#endif //TRIENODE_TRIENODE_H
