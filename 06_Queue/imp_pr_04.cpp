// implement stack using queue
// Pop effecient...

#include<iostream>
#include<queue>
using namespace std;

class stack{
    queue<int> q;
    public:
    stack() {}

    void push(int x){
        queue<int> temp;
        while (!q.empty()){
            temp.push(q.front());
            q.pop();
        }
        if (q.size() == 0){
            q.push(x);
        }
        while(!temp.empty()){
            q.push(temp.front());
            temp.pop();
        }
    }
    void pop(){
        q.pop();
    }

    bool isEmpty(){
        return q.empty();
    }

    int getFront(){
        return q.front();
    }


};

int main(){
    stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.pop();
    while(!s.isEmpty()){
        cout << s.getFront()<<"  "<<endl;
        s.pop();
    }
}

