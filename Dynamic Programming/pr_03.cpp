// pr_03
// given a triangle array return the minimum path sum from top to bottom .

#include<iostream>
#include<vector>
using namespace std;

int f(vector<vector<int>> &v){
    int i=0,j=0;
    int ans=v[0][0];
    while(i<v.size()-1){
        int temp;
        if (v[i+1][j] < v[i+1][j+1]){
            ans += v[i+1][j];
            temp=j;
        }
        else{
            ans += v[i+1][j+1];
            temp=j+1;
        }
        i++;
        j=temp;
        // cout<<ans<<"**";
    }
    return ans;
}

int main(){
    vector<vector<int>> v = {{3,4},{6,5,7},{4,1,8,3},{2,6,8,9,3}};
    cout<<"hello"<<endl;
    cout<<f(v);
}


// runtime error