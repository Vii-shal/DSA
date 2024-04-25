// insertion sort 

#include<iostream>
using namespace std;

int main(){
    int a[]={11,8,15,9,4};
    int n=5;
    for (int i=1;i<n;i++){
        int curr = a[i];
        int j=i-1;
        while (j>=0 && a[j]>curr){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = curr;
    }

    for (int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
} 