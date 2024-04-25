// insert at bottom

#include<iostream>
#include<stack>
using namespace std;

stack<int> insertAtBottom(stack<int> &input , int x){
    stack<int> temp;
    while(!input.empty()){
        int curr = input.top();
        input.pop();
        temp.push(curr);
    }
    stack<int> res;
    res.push(x);
    while (!temp.empty()) {
        int curr = temp.top();
        temp.pop();
        res.push(curr);
    }
    return res;
}

int main(){
    stack <int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    int x=9;
    stack <int> ans = insertAtBottom(st,x);
    while (not ans.empty()){
        int curr = ans.top();
        ans.pop();
        cout<<curr<<endl;
    }
}