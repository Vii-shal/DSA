// implement queue using stack
// Pop effecient...

#include<iostream>
#include<stack>
using namespace std;

class queue{
    stack<int> st;
    public:
    queue() {};

    void push(int x){
        stack<int> temp;
        while (!st.empty()){
            temp.push(st.top());
            st.pop();
        }
        st.push(x);
        while(!temp.empty()){
            st.push(temp.top());
            temp.pop();
        }
    }
    void pop(){
        st.pop();

    }

    bool isEmpty(){
        return st.empty();
    }

    int getFront(){
        return st.top();
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

