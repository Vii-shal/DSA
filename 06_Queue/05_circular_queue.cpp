// queue implementation using array/vector 

#include<iostream>
#include<vector>
using namespace std;

class Queue{
    int front;
    int back;
    vector<int> v;
    int cs;
    int ts;
    public:
    Queue(int n){
        v.resize(n);
        this->back = n-1;
        this->front= 0;
        this->cs = 0;
        this->ts = n;
    }

    void enqueue(int data){
        if(isFull()) return;
        back = (back+1) % ts;
        v[back] =data ;
        cs++;
    }

    void dequeue(){
        if(isEmpty()) return;
        front = (front+1)%ts;
        cs--;
    }

    int getFront(){
        if (this->front == -1) return -1;
        return this->v[this->front];
    }

    int getSize(){
        return this->back - this->front +1;
    }

    bool isEmpty(){
        return this->cs == 0;
    }
    bool isFull(){
        return this->cs==ts;
    }


};

int main(){
    Queue qu(4);
    qu.enqueue(10);
    qu.enqueue(20);
    qu.enqueue(30);
    qu.dequeue();
    qu.enqueue(40);
    qu.dequeue();
    qu.dequeue();
    qu.dequeue();
    qu.enqueue(400);
    qu.enqueue(500);
    cout<<qu.getSize()<<endl;

    while (not qu.isEmpty()){
        cout <<qu.getFront()<<"  "<<endl;
        qu.dequeue();
    }

}