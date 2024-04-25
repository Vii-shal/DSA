// coin changes 

#include<iostream>
#include<vector>
using namespace std;


int fbu(vector<int> &coins,int x,int n){
    vector<int> dp(1000005,0);
    int MOD = 1000000007;
    dp[0]=1;
    for (int j=0;j<n;j++){
        for (int i=1;i<=x;i++){
            if (i-coins[j] < 0) continue;
            dp[i] = (dp[i]%MOD + dp[i-coins[j]]%MOD)%MOD;
        }
    }
    return dp[x];
}


int main(){
    int n;
    cin>>n;
    int x;
    cin>>x;
    vector<int> coins(n);
    for (int i=0;i<n;i++) cin>>coins[i];
    cout<<fbu(coins,x,n)<<endl;
}





// input--------
// 3 9
// 2 3 5
// output------
// 3