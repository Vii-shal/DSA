// find first and last index of given number "target" .

#include<iostream>
#include<vector>
using namespace std;

int upperbound(vector<int> &v,int target){                // last occ
    int l=0;
    int r=v.size()-1;
    int ans  = -1;
    while (l<=r) {
        int mid = l+((r-l)/2);
        if (v[mid] > target){
            ans=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
        // if (v[mid] <= target){
        //     l=mid+1;
        // }
        // else{
        //     r=mid-1;
        //     ans=mid;
        // }        
    }
    return ans;
}
int lowerbound(vector<int> &v,int target){                   // first occ
    int l=0;
    int r=v.size()-1;
    int ans  = -1;
    while (l<=r) {
        int mid = l+((r-l)/2);
        if (v[mid] >= target){
            ans=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
            // r=mid-1;
        }
    }
    return ans;
}


int main(){
    vector <int> v={1,1,2,2,2,3,4,5,5,5};
    int target;
    cin>>target;

    vector<int> result;
    int lb = lowerbound(v,target);
    if (v[lb] != target){
        result.push_back(-1);
        result.push_back(-1);
    }
    else{
        int ub = upperbound(v,target);
        result.push_back(lb);
        result.push_back(ub-1);
    }
    cout<<result[0]<<"  "<<result[1];
    
}