// implement queue using stack
// Push effecient...

#include<iostream>
#include<stack>
using namespace std;

class queue{
    stack<int> st;
    public:
    queue() {};
    void push(int x){
        st.push(x);
    }
    void pop(){
        stack<int> temp;
        if (st.empty()) return;
        while(!st.empty()){
            int curr = st.top();
            st.pop();
            temp.push(curr);
        }
        temp.pop();
        while(!temp.empty()){
            int curr = temp.top();
            temp.pop();
            st.push(curr);
        }
    }

    bool isEmpty(){
        return st.empty();
    }

    int getFront(){
        stack<int> temp;
        while(!st.empty()){
            int curr = st.top();
            st.pop();
            temp.push(curr);
        }
        int front = temp.top();
        while(!temp.empty()){
            int curr = temp.top();
            temp.pop();
            st.push(curr);
        }
        return front;
    }

};

int main(){
    queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.pop();
    while(!q.isEmpty()){
        cout << q.getFront()<<"  "<<endl;
        q.pop();
    }
}

