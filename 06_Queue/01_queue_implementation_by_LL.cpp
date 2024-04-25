// Queue implementation using linked list .

#include<iostream>
using namespace std;

class node{
    public:
    int val;
    node * next;
    node(int value){
        this->val =value ;
        this->next = NULL;
    }
};

class queue{
    node * head;
    node * tail;
    int size;
    public:
    queue(){
        this->head = NULL;
        this->tail = NULL;
        this->size = 0;
    }

    void enqueue(int value){
        node * new_node = new node(value);
        if (this->head == NULL){
            this->head = new_node;
            this->tail = new_node;
        }
        else{
            this->tail->next = new_node;
            this->tail = new_node;
        }
        this->size++;
    }

    void dequeue(){
        if (this->head == NULL){
            return;
        }
        else{
            node * temp = this->head;
            this->head = this->head->next;
            if (this->head == NULL)  this->tail = NULL;
            free(temp);
            this->size--;
        }
    }

    int getSize(){
        return this->size;
    }

    bool isEmpty(){
        return this->head == NULL;
    }

    int getFront(){
        if (this->head == NULL) return -1;
        return this->head->val;
    }

};

int main(){
    queue qu;
    qu.enqueue(1);
    qu.enqueue(10);
    // qu.enqueue(20);
    qu.enqueue(30);
    qu.enqueue(40);
    qu.dequeue();
    qu.enqueue(50);
    cout<<qu.getSize()<<endl;

    while (not qu.isEmpty()){
        cout <<qu.getFront()<<"  "<<endl;
        qu.dequeue();
    }

}