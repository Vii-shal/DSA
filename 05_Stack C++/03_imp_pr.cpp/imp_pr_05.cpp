// prev Greater Element.
// (1) -> rev array
// (2) -> apply ngl / nsl
// (3) -> reverse back to original order

// similiarly for prev smaller element .

#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> preGreaterElement(vector<int> &v){

    reverse(v.begin(),v.end());

    vector<int> res(v.size() , -1);
    stack<int> s;
    s.push(0);
    for (int i=1;i<v.size();i++){
        while (!s.empty() and v[i] > v[s.top()]){
            res[s.top()] = v[i];
            s.pop();
        }
        s.push(i);
    }
    // while(not s.empty()){               // not needed as we already initialize our araay with -1.
    //     res[s.top()] = -1;
    //     s.pop();
    // }
    reverse(res.begin(),res.end());
    return res;
}

int main(){
    vector<int> v = {4,6,3,1,0,9,5,6,7,3,2};
    vector<int> ans = preGreaterElement(v);
    for (int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }


}