// input ->  [0 , 5 , 0 , 3 , 42]
// output ->  [5 , 3 , 42 , 0 , 0]

#include<iostream>
using namespace std;

int main(){
    int a[] = {0,5,0,2,42};
    int n=5;
    
    for (int i=0;i<n-1;i++){
        bool flag = false;
        for (int j=0;j<n-1-i;j++){
            if (a[j]==0){
                swap(a[j],a[j+1]);
            }
        }
    }

    for (int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}