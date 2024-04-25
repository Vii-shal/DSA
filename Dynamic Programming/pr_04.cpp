// matrix multiplication

#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> dp;

//top down-----------------------------------------------------------------
int f (int i,int j,vector<int> &arr){
    if (i==j or i+1==j) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    int ans = INT16_MAX;
    for (int k=i+1;k<j;k++){
        ans = min(ans,f(i,k,arr) + f(k,j,arr) + arr[i]*arr[j]*arr[k]);
    }
    return dp[i][j] = ans;
}

//bottm up------------------------------------------------------------------
int fbu(vector<int> v){
    dp.clear();
    dp.resize(1005,vector<int> (1005,0));
    int n=v.size();
    int ans=0;
    // if length is 1 or 2 then ans =>0
    for (int len = 3;len<=n;len++){
        for (int i=0;i+len-1<n;i++){
            int j=i+len-1;
            dp[i][j] = INT16_MAX;
            for (int k=i+1;k<j;k++){
                dp[i][j] = min(dp[i][j],dp[i][k] + dp[k][j] + v[i]*v[j]*v[k]);
                ans = dp[i][j];
            }
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    dp.clear();
    dp.resize(1005,vector<int> (1005,-1));
    for (int i=0;i<n;i++) cin>>arr[i];
    cout<<f(0,n-1,arr)<<endl;
    cout<<fbu(arr);
    
}




// 5
// 40 20 30 10 30
// 26000