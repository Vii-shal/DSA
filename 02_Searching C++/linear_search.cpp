#include<iostream>
using namespace std;

int main() {
    int a[]={5,6,4,98,14,36,21,27,11,34};
    int n = sizeof(a)/sizeof(a[0]);
    int target=34;
    for (int i=0;i<n;i++){
        if (a[i] == target){
            cout<< "found at index "<<i<<" ";
        }
    }
}
