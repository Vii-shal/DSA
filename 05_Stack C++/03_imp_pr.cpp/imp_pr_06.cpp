// Important
// Given a series of N daily price quotes for a stack , we need to calculate the span of the stock's price for all days .  
// The span of stock's price in one day is the maximum number of consecutive days (starting from day and going backword) for which
// the stock price was less then or equal to price of that day.

#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> pgl(vector<int> &v){

    reverse(v.begin(),v.end());

    vector<int> ans(v.size(),-1);
    stack<int> st;
    st.push(0);
    for(int i=1;i<v.size();i++){
        while (!st.empty() and v[i]>v[st.top()]){
            ans[st.top()] = v.size()-i-1;
            st.pop();
        }
        st.push(i);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

vector<int> span(vector <int> &vec){
    vector<int> span_list(vec.size(),1);
    for (int i=0;i<vec.size();i++){
        span_list[i] = i - (vec[i]);
    }
    return span_list;
}

int main(){
    // vector<int> v = {4,6,3,1,0,9,5,6,7,3,2};
    vector<int> v = {100,80,60,70,60,75,85};
    vector<int> ans_pgl = pgl(v);
    for (int i=0;i<ans_pgl.size();i++){
        cout<<ans_pgl[i]<<" ";
    }
    cout<<endl;

    vector<int> ans = span(ans_pgl);
    for (int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}