// Next Greater Element.

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> nextGreaterElement(vector<int> &v){
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
    return res;
}

int main(){
    vector<int> v = {4,6,3,1,0,9,5,6,7,3,2};
    vector<int> ans = nextGreaterElement(v);
    for (int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }


}