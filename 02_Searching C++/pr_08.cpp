#include<iostream>
#include<vector>
using namespace std;

int peak(vector<int> &v){
    int l=0;
    int r=v.size()-1;
    int ans=-1;
    while(l<=r){
        int mid = l+((r-l)/2);
        if (v[mid]>v[mid-1]){
            ans = mid;
            l=mid+1;
        }
        else {
            r=mid-1;
        }
    }
    return ans;
}

int main(){
    
    vector<int> v = {7,8,6,5,3,2,1};
    cout<<peak(v);
 
}