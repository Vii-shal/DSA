// given a rotataed sorted array of integers which contain distinct elememts ,return index of target if it is in the array 

#include<iostream>
#include<vector>
using namespace std;

int findIndexOfTargetEle(vector<int> &v,int target){
    int l=0;
    int r=v.size()-1;
    while (l<=r) {
        int mid = l+((r-l)/2);
        if (v[mid]==target) return mid;
        if (v[mid]>v[l]){
            if (target>=v[l] && target<=v[mid]){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        else{
            if (target>=v[mid] && target<=v[r]){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
    }
    return -1;
}
int main(){
    vector<int> v={4,5,6,7,0,1,2};
    int target;
    cin>>target;
    cout<<findIndexOfTargetEle(v,target)<<endl;

}