#include<iostream>
#include<algorithm>
using namespace std;
int const N = 1e3;

void heapify(int arr[],int size,int curr){
    while (curr*2 <= size){
        int leftchild = curr*2;
        int rightchild = curr*2 + 1;
        int maxchild = leftchild;
        if (rightchild <= size && arr[rightchild]>arr[leftchild]){
            maxchild=rightchild;
        }
        if (arr[curr] >= arr[maxchild]){
            return;
        }
        swap(arr[curr],arr[maxchild]);
        curr = maxchild;
    }
}

void heapified_maxheap(int arr[],int size){
    for (int i=size/2;i>0;i--) {
        heapify(arr,size,i);
    }
}

int heapSort(int arr[],int size){
    heapified_maxheap(arr,size);
    while (size >1){
        swap(arr[1],arr[size]);
        size--;
        heapify(arr,size,1);
    }
}


int main(){
    int arr[N] = {-1,60,10,80,50,5,20,70};
    int size = 7;
    heapSort(arr,size);
    for (int i=1;i<=size;i++){
        cout<<arr[i]<<" ";
    }
}