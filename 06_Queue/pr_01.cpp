#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void reverse(queue <int> &q){
    stack<int> st;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        st.push(curr);
    }
    while(!st.empty()){
        int curr = st.top();
        st.pop();
        q.push(curr);
    }
}

int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    reverse(q);
    while (!q.empty()){
        cout<<q.front()<<"  ";
        q.pop();
    }

}