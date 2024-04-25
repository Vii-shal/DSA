// binary search     [iterative implementation]
// time complexity = O(log(n))
// space complexity = O(1)


#include<iostream>
#include<vector>
using namespace std;

void binary_s(vector<int> &a,int target){
    int l=0;
    int r=a.size()-1;
    while (l<=r) {
        int mid = (l+r)/2;
        // int mid = l + ((r-l)/2)                                  modified mid to tackle overflow
        if (a[mid]==target){
            cout<<"found at index "<<mid<<endl;
            break;
        }
        else if(a[mid]<target){
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
}

int main(){
    vector<int> a={1,5,9,16,18,22,31,38};
    int target=18;
    binary_s(a,target);
    
}