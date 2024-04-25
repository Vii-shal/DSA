// write a program to find Kth smallest element in an array using quickSort

#include<iostream>
using namespace std;

int partition(int a[],int l,int r){
    int pivot = a[r];
    int j=l;
    for (int i=l;i<r;i++){
        if (a[i]<pivot){
            swap(a[i],a[j]);
            j++;
        }
    }
    swap(a[j],a[r]);
    return j;
}

int kthSmallest(int a[],int l,int r,int k){
    if (k>0 && k<=r-l+1){
        int pos = partition(a,l,r);
        if (pos-l == k-1){
            return a[pos];
        }
        else if (pos-l > k-1){
            return kthSmallest(a,l,pos-1,k);
        }
        else{
            return kthSmallest(a,pos+1,r,k-pos+l-1);
        }
    }
    return INT16_MAX;
}

int main(){
    int a[]={3,5,2,1,4,7,8,6};
    int n=sizeof(a)/sizeof(a[0]);
    int k=5;
    cout<<kthSmallest(a,0,n-1,k);    
    
}