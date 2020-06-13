#include <iostream>
#include<set>
#include<unordered_map>
using namespace std;
int main() {
    //pairs
    /*pair<int,char> p;
    pair<int,char> p2(1,'a');
    p = make_pair(2,'b');
    cout << p2.first << " " <<p2.second<< endl;
    cout << p.first << " " <<p.second<< endl;*/
    //Sets
    /*set<int> s;
    int arr[] = {1,2,3,4,5,6,5};

    for(int i=0;i<7;i++){
        s.insert(arr[i]);
    }
    set<int>::iterator it;
    for(it = s.begin();it!=s.end();it++){
        cout << *it << endl;
    }
    if(s.find(7) == s.end()) {
        cout << "Element not found";
    }
    else{
        cout << "Element found";
    }*/
    //Maps
    int arr[] = {1,2,3,4,5,6,5};
    unordered_map<int,int> m;
    for(int i : arr){
        m[i]+=1;
    }
    unordered_map<int,int>::iterator it;
    m.erase(1);
    for(it = m.begin(); it != m.end(); it++){
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}
