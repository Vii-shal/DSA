//   insert at a index .

#include<iostream>
#include<stack>
using namespace std;

void insertAtIndex(stack<int> &st , int x , int idx){
    stack<int> temp;
    int n = st.size();
    int count = 0;
    while (count < n - idx){
        int curr = st.top();
        st.pop();
        temp.push(curr);
        count++;
    }
    temp.push(x);
    while(not temp.empty()){
        int curr = temp.top();
        temp.pop();
        st.push(curr);
    }
			     
}

int main(){
    stack <int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    insertAtIndex(st,22,4);
    while (not st.empty()){
        int curr = st.top();
        st.pop();
        cout<<curr<<endl;
    }
}