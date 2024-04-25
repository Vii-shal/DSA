// important ...............................
// by me
// histogram / rectangle area.

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

vector<int> nsl(vector<int> v){
    vector<int> res(v.size(),-1);
    stack <int> st;
    st.push(0);
    for (int i=1;i<v.size();i++){
        while(!st.empty() && v[st.top()] > v[i]){
            res[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    return res;
}

vector<int> psl(vector<int> v){

    reverse(v.begin(),v.end());

    vector<int> res(v.size(),-1);
    stack <int> st;
    st.push(0);
    for (int i=1;i<v.size();i++){
        while(!st.empty() && v[st.top()] > v[i]){
            res[st.top()] = v.size() - i -1;
            st.pop();
        }
        st.push(i);
    }

    reverse(res.begin(),res.end());
    return res;
}

vector<int> rectAreaList(vector<int> v){
    vector<int> i = nsl(v);
    vector<int> j = psl(v);
    for (auto x:i) {
        cout<<x<<" ";
    }
    cout<<endl;
    for (auto x:j) {
        cout<<x<<" ";
    }
    cout<<endl;
    vector<int> result(v.size());
    for (int k=0;k<v.size();k++){

        if (i[k]<j[k]){                                                  // if we have last ele or when "nsl > psl"
           result[k] =  v[k]*(k-j[k]); 
        }
        else{
           result[k] =  (v[k]) * (abs(i[k])-j[k]-1); 
        }
    }
    return result;

}

int main(){
    vector<int> v = {2,1,5,6,2,3,0,2,1,5,6,2,3};

    vector<int> nsl_ans = nsl(v);
    for (auto x:nsl_ans) {
        cout<<x<<" ";
    }
    cout<<endl;

    vector<int> psl_ans = psl(v);
    for (auto x:psl_ans) {
        cout<<x<<" ";
    }
    cout<<endl;

    vector<int> rect_area_ans = rectAreaList(v);
    int maxArea = INT16_MIN;
    for (auto x:rect_area_ans) {
        cout<<x<<" ";
        maxArea = max(maxArea,x);
        
    }
    cout<<endl;
    cout<<"maxArea is : "<<maxArea<<endl;
}