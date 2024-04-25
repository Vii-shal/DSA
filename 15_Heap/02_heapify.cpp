#include<iostream>
#include<algorithm>
using namespace std;
int const N = 1e3;

void heapifyMinHeap(int arr[],int &size,int curr){
    while (2*curr <= size){
        int leftchild = 2*curr;
        int rightchild = 2*curr+1;
        int minchild = leftchild;
        if (rightchild<=size && arr[leftchild] > arr[rightchild]){
            minchild = rightchild;
        }
        if (arr[minchild] >= arr[curr]){
            return;
        }
        swap(arr[minchild],arr[curr]);
        curr = minchild;
    }
}


void heapifyMaxHeap(int arr[],int size,int curr){
    while (curr*2 <= size){
        int leftchild = curr*2;
        int rightchild = curr*2 + 1;
        int maxchild = leftchild;
        if (rightchild <=size && arr[leftchild] < arr[rightchild]){
            maxchild = rightchild;
        }
        if (arr[curr] >= arr[maxchild]){
            return;
        }
        swap(arr[maxchild],arr[curr]);
        curr = maxchild;
    }
}


int main(){
    int arr[N] = {-1,60,10,80,50,5,20,70};
    int size=7;
    //min heap
    for (int i=size/2;i>0;i--){
        // i->parent node
        heapifyMinHeap(arr,size,i);
    }
    cout<<"Heapified array is : ";
    for (int i=1;i<=size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;


    // max heap 
    for (int i=size/2;i>0;i--){
        // i->parent node
        heapifyMaxHeap(arr,size,i);
    }
    cout<<"Heapified array is : ";
    for (int i=1;i<=size;i++){
        cout<<arr[i]<<" ";
    }
}