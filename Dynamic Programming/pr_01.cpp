// frog jump

#include<iostream>
#include<vector>
using namespace std;

vector<int> dp;

int f(vector<int> &heights,int i,int k){
    if (i==heights.size()-1) return 0;
    if (dp[i]!=-1) return dp[i];
    int ans=INT16_MAX;
    for (int j=1;j<=k;j++){
        if ((i+j) >= heights.size()) break;
        ans = min(ans,abs(heights[i]-heights[i+j]) + f(heights,i+j,k));    
    }
    return dp[i] = ans;
}

int fbu(vector<int> &heights,int k){
    int n=heights.size();
    dp[n-1]=0;
    for (int i=n-2;i>=0;i--){             // order
        for (int j=1;j<=k;j++){
            if ((i+j) >= n) break;
            dp[i] = min(dp[i],abs(heights[i]-heights[i+j]) + dp[i+j]);    
        }
    }
    return dp[0];
}

int main(){
    dp.clear();
    dp.resize(10005,-1);
    // vector<int> v = {10,30,40,50,20};
    vector<int> v = {10,20,10};
    // int k=3;
    int k=1;
    cout<<f(v,0,k)<<endl;;
    cout<<fbu(v,k)<<endl;;

}

// n=3 , k=1 , {10,20,10}
// ans = 20