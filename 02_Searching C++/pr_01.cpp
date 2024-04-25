// find the first occurence of the given element x , given that the array is sorted , if no occurence of x is found then return -1.

#include<iostream>
#include<vector>
using namespace std;

int first_occ(vector <int> &a,int target){
    int l=0;
    int r=a.size()-1;
    int ans=-1;
    while (l<=r) {
        int mid=l+((r-l)/2);
        if (a[mid]==target){
              ans = mid;
              r=mid-1;
        }
        else if (a[mid]<target){
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    return ans;

}

int main(){
    vector<int> a={2,5,5,5,5,6,6,8,9,9,9,9};
    int target = 6;
    cout<<first_occ(a,target);
}