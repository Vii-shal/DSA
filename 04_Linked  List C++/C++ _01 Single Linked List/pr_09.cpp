// Given the head of a linked list , rotate the list to right by k places . 

#include<iostream>
using namespace std;

class node{
    public:
    int val;
    node* next=NULL;
    node(int value){
        val = value;
        next = NULL;
    }
};

class linkedList{
    public :
    node * head;
    linkedList(){
        head = NULL;
    }

    void insertAtTail(int k){
        node * new_node = new node(k);
        if (head == NULL) {
            head = new_node;
            return;
        }

        node *temp = head;
        while (temp->next != NULL ){
            temp = temp->next;
        }
        temp->next = new_node;
    }

    void display(){
        node * temp = head;
        while (temp!=NULL) {
            cout<<temp->val<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
};


node * rotateByK(node * &head,int k){
    // 1. find length of LL
    int n=0;
    // 2. find tail node
    node * tail = head;

    while (tail->next != NULL){
        n++;
        tail= tail->next;
    }
    n++;    //for including last node

    k=k%n;
    if (k==0) return head;

    // 3. traverse n-k nodes
    node * temp = head;
    for (int i=1;i<n-k;i++){
        temp = temp->next;
    }
    //temp is pointing to (n-k)th node
     
     node * newhead = temp->next;
     temp->next = NULL;
     tail->next = head;
     head = newhead;
     return head;
    
}


int main(){
    linkedList ll;
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(4);
    ll.insertAtTail(5);
    ll.insertAtTail(6);
    ll.insertAtTail(7);
    ll.insertAtTail(8);
    ll.display();

    rotateByK(ll.head,2);
    ll.display();
    
}