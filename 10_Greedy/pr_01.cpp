// minimum cost to cut a board into squares.
// input-----------
// m=6 , n=4   , x[]={2,1,3,1,4} (vertical)    , y[]={4,1,2} (horizontal)
// output----------
// 

#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long int
using namespace std;

bool cmp(int x,int y){
    return x>y;
}

ll minCostToBreakGrid(int m,int n,vector<ll> &vertical , vector<ll> &horizontal){
    sort(vertical.begin(),vertical.end(),cmp);
    sort(horizontal.begin(),horizontal.end(),cmp);
    int hz = 1;  // horizontal block count
    int vr = 1;  // verticle block count
    int h=0,v=0;  // pointer 
    ll ans=0;

    while (h < horizontal.size() and v < vertical.size()){
        if (vertical[v] > horizontal[h]){
            ans += vertical[v]*vr;
            hz++;
            v++;
        }
        else {
            ans += horizontal[h]*hz;
            vr++;
            h++;
        }
    }
    while (h<horizontal.size()){
        ans += horizontal[h]*hz;
        vr++;
        h++;        
    }
    while (v<vertical.size()){
        ans += vertical[v]*vr;
        hz++;
        v++;
    }

    return ans;
}

int main(){
    int m,n;
    cin>>m>>n;
    vector<ll> horizontal, vertical;
    for (int i=0;i<m-1;i++){
        int x;
        cin>>x;
        vertical.push_back(x);
    }
    for (int i=0;i<n-1;i++){
        int x;
        cin>>x;
        horizontal.push_back(x);
    }
    cout<<minCostToBreakGrid(m,n,horizontal,vertical);

}


// input-----------
// 6 4
// 2
// 1
// 3
// 1
// 4
// 4
// 1
// 2
// output-----------
// 420