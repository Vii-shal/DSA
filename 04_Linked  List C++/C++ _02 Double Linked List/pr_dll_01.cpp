// reverse 

#include<iostream>
using namespace std;

class node{
    public:
    int val;
    node * next;
    node * prev;
    node(int value){
        val = value;
        next = NULL;
        prev = NULL;
    }
};

class doublyLinkedList{
    public:
    node* head, *tail ;
    doublyLinkedList(){
        head = NULL;
        tail = NULL;
    }

    void insertAtEnd(int value){
        node* newNode=new node (value);
        if (head==NULL){
            head = newNode;
            tail = newNode;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void display(){
        node * temp = head;
        while (temp != NULL){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

};

void reverseDLL(node * &head, node * &tail){
    node * currptr = head;
    node * prevptr = NULL;
    while (currptr != NULL){
        node * nextptr = currptr->next;
        currptr->next = prevptr;
        currptr->prev = nextptr;
        prevptr = currptr;
        currptr = nextptr;
    }
    // swapping head and tail pointers
    // tail = head;
    // head  = currptr->prev;

    node * newhead = tail;
    tail = head;
    head = newhead;
}


int main(){
    doublyLinkedList dll;
    dll.insertAtEnd(1);
    dll.insertAtEnd(2);
    dll.insertAtEnd(3);
    dll.insertAtEnd(4);
    dll.insertAtEnd(5);
    dll.display();
    reverseDLL(dll.head,dll.tail);
    dll.display();
}