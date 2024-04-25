// given a rotated sorted array , find index of minimum element in an array .
// all elements are unique .

#include<iostream>
#include<vector>
using namespace std;

int lowest(vector <int> &v){
    if (v.size()==1) return 0;
    int l=0;
    int r=v.size()-1;
    if (v[l]<v[r]){
        return 0;
    }
    while (l<=r){
       int mid = l + ((r-l)/2);
       if (v[mid] > v[mid+1]) return mid+1;
       if (v[mid] < v[mid-1]) return mid;
       if (v[mid]>v[l]){
        l=mid+1;
       }
       else{
        r=mid-1;
       }
    }
    return -1;
}

int main(){
    vector<int> v = {6,7,9,3,4,5};
    cout<<lowest(v);
}