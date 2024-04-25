// search elements in rotated sorted array with duplicate elements . return 1 if the elements is found ,else return -1

#include<iostream>
#include<vector>
using namespace std;

int search(vector<int> &v,int target){
    int l=0;
    int r=v.size()-1;

    while (l<=r){
        int mid=l+((r-l)/2);
        if (v[mid] == target){
            return 1;
        }
        if (v[mid]>v[l]){
            if (target>=v[l] && target<=v[mid]){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        else{
            if (target>=v[mid]  && target<=v[r]){
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
    vector<int> v={0,0,0,1,1,1,2,0,0,0};
    int target;cin>>target;
    cout<<"ans is "<<search(v,target);
}