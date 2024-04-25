// merge two sorted linked list .

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

node * merge(node* &head1 , node*&head2){

    node* dummy_head_node = new node(-1);
     
    node *ptr1 = head1;
    node *ptr2 = head2;
    node *ptr3 = dummy_head_node;

    while (ptr1 && ptr2){
        if (ptr1->val < ptr2->val){
            ptr3->next = ptr1;
            ptr1 = ptr1->next;
        }
        else{
            ptr3->next = ptr2;
            ptr2 = ptr2->next;
        }
        ptr3 = ptr3->next;
    }
    if (ptr1){
        ptr3->next  = ptr1 ;
    }
    else{
        ptr3->next  = ptr2 ;
    }

    return dummy_head_node->next;
}




int main(){
    linkedList ll;
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(8);
    ll.insertAtTail(15);
    ll.insertAtTail(17);
    ll.display();

    linkedList ll2;
    ll2.insertAtTail(6);
    ll2.insertAtTail(7);
    ll2.insertAtTail(8);
    ll2.insertAtTail(8);
    ll2.insertAtTail(10);
    ll2.insertAtTail(20);
    ll2.display();

    linkedList ll3;
    ll3.head = merge(ll.head,ll2.head);
    ll3.display();



}