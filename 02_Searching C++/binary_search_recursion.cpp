// binary search using recursion          [recursive implementation]
// time complexity = O(log(n))
// space complexity = O(log(n))


#include<iostream>
using namespace std;

void binarySearch(int a[],int l,int r,int target){
    if (l>r){
        return ;
    }
    int mid=(l+r)/2;
    if (a[mid]==target){
        cout<<"found at index "<<mid<<endl;
    }
    else if(a[mid]<target){
        binarySearch(a ,mid +1  ,r   ,target);
    }
    else{
        binarySearch(a ,l ,mid-1,target);
    }
}

int main(){
    int a[]={5,6,8,9,12,15,18,19,23};
    int n=sizeof(a)/sizeof(a[0]);
    binarySearch(a,0,n-1,9);
}






