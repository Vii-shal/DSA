// rverseing k nodes in linked list 

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

node * reversekLL(node * &head,int k){
    node * preptr = NULL;
    node * currptr = head;
    int counter = 0;
    while (currptr != NULL && counter<k){    //reversing first k nodes
        node * nextptr = currptr->next;
        currptr->next = preptr;
        preptr = currptr;
        currptr = nextptr;
        counter++;
    }

    // currptr will give us  (k+1)th node 
    if (currptr != NULL){
        node * new_head = reversekLL(currptr , k);
        head->next = new_head;
    }
    return preptr;  //preptr will give new_head of connected linkedlist 
}


int main(){
    linkedList ll;
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(4);
    ll.insertAtTail(5);
    ll.insertAtTail(6);
    ll.display();
    ll.head = reversekLL(ll.head,4);
    ll.display();

}