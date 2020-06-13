#include<iostream>
#include<map>
using namespace std;

char firstNonRepeatingChar(string input){
    map<char,int> frequency;
    for(int i=0;i<input.length();i++){
        char currChar = input[i];
        frequency[currChar]++;
    }
    for(int i=0;i<input.length();i++){
        if(frequency[input[i]] == 1) return input[i];
    }
    return input[0];
}
int main() {
    string input;
    cin >> input;
    char result = firstNonRepeatingChar(input);
    cout << result << endl;
    return 0;
}
