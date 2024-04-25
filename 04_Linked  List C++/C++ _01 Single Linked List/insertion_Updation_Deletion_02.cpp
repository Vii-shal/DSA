// insertion on linked list

#include<iostream>
using namespace std;

class node{
    public:
    int val;
    node* next;
    node(int value){
        val =value ;
        next = NULL;
    }
};

//  Add a node at start 
void insertAtHead(node* &head , int k){
    node * new_node = new node(k);
    new_node->next = head;
    head = new_node;
}

//  Add a node at end 
void insertAtTail(node* &head,int k){
    node * temp = head;
    node * new_node  = new node(k);
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new_node;
}

//  Add a node at a position 
void insertAtPosition(node * &head,int k,int pos){
    if (pos == 0){
        insertAtHead(head,k);
        return;
    }
    node * temp = head;
    node * new_node = new node(k);
    int curr=0;
    while (curr != pos-1){
        temp = temp->next;
        curr++;
    }
    // temp is pointing to node at pos-1
    new_node->next = temp->next;
    temp->next = new_node;
}

// Updation at a position 
void updateAtPos(node* &head , int k ,int pos){
    node * temp = head;
    int curr=0;
    while (curr!=pos){
        temp = temp->next;
        curr++;
    }
    temp->val = k;
}

//  delete at start
void delFromStart(node*& head ){
    node*temp = head;    // node to be deleted
    head = head->next;
    free(temp);
}

// delete at tail
void delFromTail(node* &head){
    node * second_last = head;
    while (second_last->next->next != NULL){
        second_last = second_last->next;
    }
    // now second_last points to secondlast node
    node * temp = second_last->next;           // node to be deleted  
    second_last->next = NULL;
    free(temp);
}

// delete at a position
void delFromPos(node* &head,int pos){
    if (pos == 0){
        delFromStart(head );
        return;
    }
    node * pre = head;
    int curr=0;
    while (curr != pos-1){
        pre = pre -> next ;
        curr++;
    }
    node* temp = pre->next;
    pre->next = pre->next->next;
    free(temp);
}

void display(node * head){
    node * temp = head;
    while (temp!=NULL) {
        cout<<temp ->val<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    node * head = NULL;
    insertAtHead(head,3);
    display(head);
    insertAtHead(head,5);
    display(head);
    insertAtTail(head,9);
    display(head);
    insertAtPosition(head,7,3);
    display(head);

    updateAtPos(head,11,2);
    display(head);

    delFromStart(head);
    display(head);
    delFromTail(head);
    display(head);
    delFromPos(head,1);
    display(head);
}