#include<iostream>
using namespace std;

void countSort(int a[],int n,int pos){
    // freq array
    int freq[10] = {0};
    for(int i=0;i<n;i++){
        freq[(a[i]/pos)%10]++;
    }

    // comulating array 
    for (int i=1;i<10;i++){
        freq[i]+=freq[i-1];
    }

    // ans array
    int ans[n];
    for(int i=n-1;i>=0;i--){
        ans[--freq[(a[i]/pos)%10]] = a[i];
    }

    for(int i=0;i<n;i++){
        a[i]=ans[i];
        // cout<<ans[i]<<"  ";
    }
}

void radixSort(int a[],int n){
    int max_ele = INT16_MIN;
    for(int i=0;i<n;i++){
        max_ele = max(max_ele,a[i]);
    }
    for (int pos=1 ; max_ele/pos > 0;pos*=10){
        countSort(a,n,pos);
    }
}

int main(){
    int a[]={5,888,147,23,54,895,99,105};
    int n=sizeof(a)/sizeof(a[0]);
    radixSort(a,n);
    cout<<"sorted array";
    for(int i=0;i<n;i++){
        cout<< a[i]<<"  ";
    }
}