// given an array arr[] and an integer k where k is smaller than size of array ,
// the task is to find the kth smallest element in the given array .
//  it is given that all array elements are distinct .

#include<iostream>
using namespace std;
int const N = 1e3;

void heapify(int arr[],int size,int curr){
    while (curr*2 <= size){
        int leftchild = curr*2;
        int rightchild = curr*2 + 1;
        int minchild = leftchild;
        if (rightchild <= size && arr[leftchild] > arr[rightchild]){
            minchild = rightchild;
        }
        if (arr[minchild] > arr[curr]){
            return;
        }
        swap(arr[minchild],arr[curr]);
        curr = minchild;
    }
}

void heapified_minHeap(int arr[],int size){
    for (int i=size/2 ;i>0 ;i--){
        heapify(arr,size,i);
    }
}

void kthSmallest(int arr[],int size,int k){
    heapified_minHeap(arr,size);
    int curr=0;
    for (int i=1;i<k;i++){
        swap(arr[1],arr[size]);
        size--;
        heapify(arr,size,1);
    }
    cout<<"The " << k << "th smallest number is : " << arr[1] << endl;
}

int main(){
    int arr[N] = {-1,7,10,4,3,20,15};
    int size=6;
    int k=3;
    kthSmallest(arr,size,k);

}

