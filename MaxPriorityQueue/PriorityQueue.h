//
// Created by Mayank Sharma on 17-04-2020.
//

#ifndef MAXPRIORITYQUEUE_PRIORITYQUEUE_H
#define MAXPRIORITYQUEUE_PRIORITYQUEUE_H

#include<vector>
#include<algorithm>
using namespace std;
class PriorityQueue {
    vector<int> pq;
public:
    PriorityQueue(){

    }
    int getSize(){
        return pq.size();
    }
    bool isEmpty(){
        return pq.size() == 0;
    }
    void insert(int element){
        pq.push_back(element);
        int childIndex = pq.size() - 1;
        while(childIndex>0) {
            int parentIndex = (childIndex - 1) / 2;
            if(pq[childIndex] > pq[parentIndex]){
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else break;
            childIndex = parentIndex;
        }
    }
    int removeMax(){
        if(pq.empty()) return 0;
        int ans = pq[0];
        pq[0] = pq[pq.size()-1];
        pq.pop_back();
        //heapify
        int parentIndex = 0;
        int lcIndex = 2 * parentIndex + 1;
        int rcIndex = 2 * parentIndex + 2;
        while(lcIndex < pq.size()){
            int maxIndex = parentIndex;
            if(pq[lcIndex] > pq[maxIndex]){
                maxIndex = lcIndex;
            }
            if(rcIndex<pq.size() && pq[rcIndex] > pq[maxIndex]){
                maxIndex = rcIndex;
            }
            if(maxIndex == parentIndex) break;
            int temp = pq[maxIndex];
            pq[maxIndex] = pq[parentIndex];
            pq[parentIndex] = temp;
            parentIndex = maxIndex;
            lcIndex = 2 * parentIndex + 1;
            rcIndex = 2 * parentIndex + 2;
        }
        return ans;
    }
    int getMax(){
        if(pq.empty()) return 0;
        return pq[0];
    }

};


#endif //MAXPRIORITYQUEUE_PRIORITYQUEUE_H
