//   reverse in same stack/address

#include<iostream>
#include<stack>
using namespace std;

void popBottom(stack<int> &input){
    stack<int> t1,t2;
    while(!input.empty()){
        int curr = input.top();
        input.pop();
        t1.push(curr);
    }
    while(!t1.empty()){
        int curr = t1.top();
        t1.pop();
        t2.push(curr);
    }
    while(!t2.empty()){
        int curr = t2.top();
        t2.pop();
        input.push(curr);
    }
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