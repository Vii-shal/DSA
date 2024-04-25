// find max value after k operation
// operation -> product of 2 smallest value and then again add product to array 

#include<iostream>
#include<queue>
using namespace std;

int maxAfterKOperation(int arr[],int n,int k){
    priority_queue<int,vector<int>,greater<int>> pq;  //minheap
    for (int i=0;i<n;i++){
        pq.push(arr[i]);
    }
    while (k--){
        int firstEle = pq.top();
        pq.pop();
        int secondEle = pq.top();
        pq.pop();
        int product = firstEle + secondEle;
        pq.push(product);
    }
    while(pq.size() != 1){
        pq.pop();
    }
    return pq.top();
}

int main() {
    int arr[] = {2,4,3,1,5};
    int n=5;
    int k=3;
    cout<<maxAfterKOperation(arr,n,k);
}