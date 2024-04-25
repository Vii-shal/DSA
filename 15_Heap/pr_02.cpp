#include<iostream>
#include<algorithm>
using namespace std;
int const N = 1e3;

void heapify(int A[],int size,int curr){
    while (curr*2+1 < size){
        int leftchild = curr*2+1;
        int rightchild = curr*2+2;
        int minchild = leftchild;
        if (rightchild <size && A[leftchild]>A[rightchild]){
            minchild=rightchild;
        }
        if (A[minchild] >= A[curr]){
            return;
        }
        swap(A[minchild],A[curr]);
        curr = minchild;
    }
}

int remove(int A[],int &size){
    int removedValue = A[0];
    A[0] = A[size-1];
    size--;
    heapify(A,size,0);
    return removedValue;
}

void sumFromK1toK2(int A[],int size,int k1,int k2){
    // 1. create minheap
    for (int i = (size/2)-1 ;i >= 0; i--) {
        heapify(A,size,i);
    }

    int sum=0;
    int elements = k2-k1-1;   // as k1 and k2 not included
    // 2. remove k1 elements
    while (k1--){
        remove(A,size);
    }
    // 3. calculate sum by removing elements 
    while (elements--){
        sum += remove(A,size);
    }
    cout<<"sum of elements between k1th and k2th smallest elements of the array : "<<sum<<endl;
}

int main(){
    int A[] = {20,8,22,4,12,10,14};
    int size = 7;
    int k1=3, k2=6;
    sumFromK1toK2(A,size,k1,k2);

}