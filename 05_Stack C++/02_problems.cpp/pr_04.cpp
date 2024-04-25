//   insert at bottom    // RECURSIVE APPROACH

#include<iostream>
#include<stack>
using namespace std;

void copyStack(stack<int> &input , int x){
    if (input.empty()){
        input.push(x);
        return;
    }
    int curr = input.top();
    input.pop();
    copyStack(input,x); 							    // recursive call
    input.push(curr) ;						     
}

int main(){
    stack <int> st;
    stack <int> ans;
    ans.push(10);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    copyStack(st,22);
    while (not st.empty()){
        int curr = st.top();
        st.pop();
        cout<<curr<<endl;
    }
}