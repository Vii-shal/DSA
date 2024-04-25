// a peak element is an element that is strictly greater than its neighbours . Find peak element and return the index to any of the peaks.
// eg.. arr={1,2,1,2,6,10,3}
//  output can be index 1 or 5 

#include<iostream>
#include<vector>
using namespace std;

int findPeak(vector<int> &v){
    int l=0;
    int n=v.size();
    int r=n-1;
    while(l<=r){
        int mid = l+((r-l)/2);
        if (mid==0){
            if (v[mid]>v[mid+1]){
                return 0;
            }
            else{
                return -1;
            }
        }
        if (mid==r){
            if (v[mid]>v[mid-1]){
                return n-1;
            }
            else{
                return n-2;
            }
        }
        else{
            if (v[mid]>v[mid-1] && v[mid]>v[mid+1]){
                return mid;
            }
            else if(v[mid]>v[mid-1]){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
    }
}
int main(){
    vector<int> v={1,2,1,2,6,10,3};
    cout<<findPeak(v);

}