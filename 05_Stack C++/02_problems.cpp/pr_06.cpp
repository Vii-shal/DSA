//   remove at bottom    // RECURSIVE APPROACH

#include<iostream>
#include<stack>
using namespace std;

void popBottom(stack<int> &input){
    if (input.size() == 1){
        input.pop();
        return;
    }
    int curr = input.top();
    input.pop();
    popBottom(input); 							    // recursive call
    input.push(curr) ;						     
}

int main(){
    stack <int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    popBottom(st);
    while (not st.empty()){
        int curr = st.top();
        st.pop();
        cout<<curr<<endl;
    }
}