#include <iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
//O(nlogn)+O(n)
vector<int> removeDuplicates2(vector<int> input){
    vector<int> result;
    sort(result.begin(),result.end());
    result.push_back(input[0]);
    for(int i=1;i<input.size();i++){
        if(input[i] != input[i-1]) result.push_back(input[i]);
    }
    return result;
}
//O(n)
vector<int> removeDuplicates(vector<int> input){
    set<int> s;
    vector<int> result;
    for(int i=0;i<input.size();i++){
        if(s.find(input[i]) == s.end()){
            s.insert(input[i]);
            result.push_back(input[i]);
        }
    }
    return result;
}


int main() {

    return 0;
}
