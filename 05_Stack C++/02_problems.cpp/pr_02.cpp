// copy contents of one stack to another in same order         // RECURSIVE APPROACH

#include<iostream>
#include<stack>
using namespace std;

void copyStack(stack<int> &input , stack<int> &result){
    if (input.empty()){
        return;
    }
    int curr = input.top();
    input.pop();
    copyStack(input,result); 							    // recursive call
    result.push(curr) ;						        // push current element into the new stack and return it
}

int main(){
    stack <int> st;
    stack <int> ans;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    copyStack(st,ans);
    while (not ans.empty()){
        int curr = ans.top();
        ans.pop();
        cout<<curr<<endl;
    }
}