//
// Created by Mayank Sharma on 17-04-2020.
//

#ifndef PRIORITYQUEUES_PRIORITYQUEUE_H
#define PRIORITYQUEUES_PRIORITYQUEUE_H

#include<vector>
#include<algorithm>
using namespace std;
class PriorityQueue {
    vector<int> pq;
public:
    PriorityQueue(){

    }
    bool isEmpty(){
        return pq.size() == 0;
    }
    int getSize() {
        return pq.size();
    }
    int getMin() {
        if(isEmpty()) return 0;
        return pq[0];
    }
    void insert(int element) {
        pq.push_back(element);
        int childIndex = pq.size() - 1;

        while(childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;
            if (pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else break;
            childIndex = parentIndex;
        }
    }
    int removeMin() {
        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();
        int parentIndex = 0;

        while(parentIndex*2+1 < pq.size()) {
            int lcIndex = 2 * parentIndex + 1;
            int rcIndex = 2 * parentIndex + 2;
            int minIndex;
            int minimum;
            if(lcIndex < pq.size() && rcIndex < pq.size()) {
                minimum = min(pq[parentIndex],min(pq[lcIndex],pq[rcIndex]));
                if(minimum!=pq[parentIndex]){
                    minIndex = pq[lcIndex]>pq[rcIndex]?rcIndex:lcIndex;
                    int temp = pq[parentIndex];
                    pq[parentIndex] = pq[minIndex];
                    pq[minIndex] = temp;
                    parentIndex = minIndex;
                }
                else break;
            }
            else if(lcIndex < pq.size()){
                minimum = min(pq[parentIndex],pq[lcIndex]);
                minIndex = pq[parentIndex]>pq[lcIndex]?lcIndex:parentIndex;
                if(minIndex!=parentIndex){
                    int temp = pq[parentIndex];
                    pq[parentIndex] = pq[minIndex];
                    pq[minIndex] = temp;
                    parentIndex = minIndex;
                }
                else break;
            }
            else if(rcIndex < pq.size()){
                minimum = min(pq[parentIndex],pq[rcIndex]);
                minIndex = pq[parentIndex]>pq[rcIndex]?rcIndex:parentIndex;
                if(minIndex!=parentIndex){
                    int temp = pq[parentIndex];
                    pq[parentIndex] = pq[minIndex];
                    pq[minIndex] = temp;
                    parentIndex = minIndex;
                }
                else break;
            }
        }
        return ans;
    }

    int removeMinOpt() {
        if(pq.empty()) return 0;
        int ans = pq[0];
        pq[0] = pq[pq.size() -1];
        pq.pop_back();
        //down heapify
        int parentIndex=0;
        int lcIndex = 2*parentIndex+1;
        int rcIndex = 2*parentIndex+2;

        while(lcIndex < pq.size()) {
            int minIndex = parentIndex;
            if(pq[minIndex] > pq[lcIndex]){
                minIndex = lcIndex;
            }
            if(rcIndex < pq.size() && pq[rcIndex] < pq[minIndex]){
                minIndex = rcIndex;
            }
            if(minIndex == parentIndex) break;
            int temp = pq[minIndex];
            pq[minIndex] = pq[parentIndex];
            pq[parentIndex] = temp;
            parentIndex = minIndex;
            lcIndex = 2*parentIndex+1;
            rcIndex = 2*parentIndex+2;
        }
        return ans;
    }
};


#endif //PRIORITYQUEUES_PRIORITYQUEUE_H
