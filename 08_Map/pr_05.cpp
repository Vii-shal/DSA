// find targetsum pair .

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> targetSumPair(vector<int> &v , int targetsum){
    unordered_map<int,int> m;
    vector<int> ans(2,-1);

    for (int i=0;i<v.size();i++){
        if (m.find(targetsum - v[i]) != m.end() ){
            ans[0] = m[targetsum - v[i]];
            ans[1] = i;
            return ans;
        }
        else{
            m[v[i]] = i;
        }
    }
    return ans;
}

int main(){
    // vector<int> v = {1,4,5,11,13,10,2};
    vector<int> v = {9,10,2,3,5};
    int x = 15;
    vector<int> res = targetSumPair(v,x);
    cout<<"Indexes are "<<res[0]<<"  "<<res[1]<<endl;

}