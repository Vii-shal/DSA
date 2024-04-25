//  selection sort

#include<iostream>
using namespace std;

int main(){
    int a[]={5,6,8,3,2};
    int n=5;

    for (int i=0;i<n-1;i++){
        int min_idx = i;
        for (int j=i;j<n;j++){
            if(a[j]<a[min_idx]){
                min_idx = j;
            } 
        }
        swap(a[min_idx],a[i]);
    }


    for (int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
