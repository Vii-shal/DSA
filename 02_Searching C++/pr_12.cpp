#include<iostream>
#include<vector>
using namespace std;

bool canPlace(vector <int> &v,int kids,int mid){
    int last_placed=v[0];
    int kid_req = 1;

    for (int i=1;i<v.size();i++){
        if (v[i] - last_placed >= mid){
            kid_req++;
            last_placed = v[i];
            if (kid_req == kids) return true;
        }
    }
    return false;
}

int find(vector<int> &v,int kids){
    int n=v.size();
    int l=0;
    int r=v[n-1]-v[0];
    int ans=-1;
    while (l<=r){
        int mid = l+((r-l)/2);
        if(canPlace(v,kids,mid)){
            ans=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    return ans;
}

int main(){
    int n;cin>>n;
    vector<int> v;
    for (int i=0;i<n;i++){
        int x;cin>>x;
        v.push_back(x);
    }
    int kids;cin>>kids;
    cout<<find(v,kids)<<endl;
}




// space -> O(1)
// time ->  O(nlog(xn-x1))