#include<iostream>
using namespace std;

void merge(int arr[],int l,int mid,int r){
    int an = mid-l+1;
    int bn = r-mid;

    int a[an];
    int b[bn];

    for (int i=0;i<an;i++){
        a[i]=arr[l+i];
    }
    for (int j=0;j<bn;j++){ 
        b[j]=arr[mid+1+j];
    }

    int i=0,j=0;                     // initial index of array a and b
    int k=l;                         // initial index of merged array
    while(i<an && j<bn){
        if(a[i]<b[j]){
            arr[k++]=a[i++];
        }
        else{
            arr[k++]=b[j++];
        }
    }
    while (i<an){
        arr[k++] = a[i++];
    }
    while (j<bn){
        arr[k++] = b[j++];
    }
}

void mergeSort(int arr[],int l,int r){
    if (l>=r) return;
    int mid = (l+r)/2;
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,r);
    merge(arr,l,mid,r);
}

int main(){
    int a[] = {5,4,8,1,6,3};
    int n = sizeof(a)/sizeof(a[0]);
    // int l=0;
    // int r=n-1;
    mergeSort(a,0,n-1);
    for (int i=0;i<n;i++){
        cout<<a[i]<<"   ";
    }
}