#include<iostream>
#include<vector>
using namespace std;

bool canDistributeCocolate(vector<int> &v,int mid,int s){
    int n=v.size();
    int curr = 0;
    int std_req = 1;

    for (int i=0;i<n;i++){
        if (v[i]>mid){
            return false;
        }
        if (curr + v[i] > mid){
            std_req++;
            curr=v[i];
            if (std_req > s){
                return false;
            }
        }
        else{
            curr+=v[i];
        }
    }
    return true;
}


int find(vector<int> &v,int s){
    int l=v[0];
    int r=0;
    for (int i = 0 ;i < v.size(); i++) {
        r+=v[i];
    }

    int ans=-1;
    while(l<=r){
        int mid = l+((r-l)/2);
        for (int i=l;i<=r;i++){
            if (canDistributeCocolate(v,mid,s)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
    }
    return ans;
}

int main(){
    // vector<int> v={12,34,67,90};
    vector<int> v={10,20,30};
    int s=3;
    cout<<find(v,s);
}