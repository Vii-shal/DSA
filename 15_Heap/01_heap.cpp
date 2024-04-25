// insertion in min heap

#include<iostream>
using namespace std;
int const N = 1e3;

void insertMinHeap(int minHeap[],int &size,int value){
    size++;
    minHeap[size] = value;
    int curr = size;
    while (curr/2 > 0 && minHeap[curr/2] > minHeap[curr]){
        swap(minHeap[curr/2],minHeap[curr]);
        curr /= 2;
    }
}

void insertMaxHeap(int maxHeap[],int &size,int value){
    size++;
    maxHeap[size] = value;
    int curr = size;
    while (curr/2 > 0 && maxHeap[curr/2] < maxHeap[curr]){        //'>' changes to '<'
        swap(maxHeap[curr/2],maxHeap[curr]);
        curr /= 2;
    }
}

void removeMinHeap(int minHeap[],int &size){
    minHeap[1] = minHeap[size];
    size--;
    int curr = 1;
    while (curr*2 <= size ){
        int leftchild = curr*2;
        int rightchild = curr*2 + 1;
        int minchild = leftchild;
        if  (rightchild <= size && minHeap[rightchild]<minHeap[leftchild]){
            minchild = rightchild;
        }
        if (minHeap[minchild] >= minHeap[curr]){
            return;
        }
        swap(minHeap[minchild],minHeap[curr]);
        curr = minchild;
    }
}

void removeMaxHeap(int maxHeap[],int &size){
    maxHeap[1] = maxHeap[size];
    size--;
    int curr = 1;
    while (curr *2 <= size){
        int leftchild = curr*2;
        int rightchild = curr*2+1;
        int maxchild = leftchild;
        if (rightchild <= size && maxHeap[rightchild]>maxHeap[leftchild]){
            maxchild = rightchild;
        }
        if (maxHeap[maxchild] <= maxHeap[curr]){
            return;
        }
        swap(maxHeap[maxchild],maxHeap[curr]);
        curr = maxchild;
    }
}

int main() {
    // min heap
    int minHeap[N] = {-1,10,20,30,40,50};
    int size1 = 5;
    int value1 = 25;
    insertMinHeap(minHeap,size1,value1);
    for(int i=1;i<=size1;i++){
        cout<<minHeap[i]<<" ";
    }
    cout<<endl;
    removeMinHeap(minHeap,size1);
    for(int i=1;i<=size1;i++){
        cout<<minHeap[i]<<" ";
    }
    cout<<endl;
    cout<<endl;


    // max heap
    int maxHeap[N] = {-1,60,40,30,20,10};
    int size2 = 5;
    int value2 = 35;
    insertMaxHeap(maxHeap,size2,value2);
    for(int i=1;i<=size2;i++){
        cout<<maxHeap[i]<<" ";
    }
    cout<<endl;
    removeMaxHeap(maxHeap,size2);
    for(int i=1;i<=size2;i++){
        cout<<maxHeap[i]<<" ";
    }
    cout<<endl;
    cout<<endl;
}