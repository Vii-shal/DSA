#include<iostream>
using namespace std;

int main(){
    int a[]={10,40,50,30,20};
    int n=5;
    for (int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<"  ";
    }
}



//   time complexity = O(n^2)
//   space complexity = O(1)