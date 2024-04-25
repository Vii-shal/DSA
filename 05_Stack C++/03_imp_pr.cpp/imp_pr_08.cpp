// important
// simplified
// histogram / rectangle area


#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int histogram(vector<int> &v){
    int n = v.size();
    stack<int> s;
    s.push(0);
    int ans = INT16_MIN;
    for (int i=1;i<n;i++){
        while (!s.empty() and v[i] < v[s.top()]){
            int el = v[s.top()];
            s.pop();
            int nsi = i;
            int psi = (s.empty())?-1 : s.top();
            ans = max(ans,el*(nsi - psi - 1));
        }
        s.push(i);
    }
    while(not s.empty()){
        int el = v[s.top()];
        s.pop();
        int nsi = n;
        int psi = (s.empty()) ? -1: s.top();
        ans = max(ans,el*(nsi-psi-1));
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    while(n--){
        int x;
        cin>>x;
        v.push_back(x);
    }
    cout<<histogram(v)<<endl;


}