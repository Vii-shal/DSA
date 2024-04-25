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


node * swapTwoAdjacentNodes(node * &head){
    if (head==NULL || head->next==NULL){
        return head;
    }

    node * secondNode = head->next;
    head->next = swapTwoAdjacentNodes(secondNode->next);
    secondNode->next = head;
    return secondNode;
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
    // ll.insertAtTail(8);
    ll.display();

    ll.head = swapTwoAdjacentNodes(ll.head);
    ll.display();
    
}