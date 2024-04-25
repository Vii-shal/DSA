// rverse linked list 

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

// reverse linked list
node * reverseLL(node * &head){
    node * prev_ptr = NULL;
    node * curr_ptr = head;
    while (curr_ptr != NULL ){
        node * next_ptr = curr_ptr->next;
        //swap the data of current and previous pointer.
        curr_ptr->next = prev_ptr;
        prev_ptr = curr_ptr;
        curr_ptr = next_ptr;
    }
    node * new_head = prev_ptr;
    return new_head;
}

// reverse linked list using recursion 
node * recursive_reverseLL(node * head){
    // base case
    if (head==NULL || head -> next == NULL ){
        return head;
    }

    // recursive case
    node * new_head = recursive_reverseLL(head->next);
    head->next->next = head;
    head->next = NULL;
    return new_head;
}


int main(){
    linkedList ll;
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(4);
    ll.insertAtTail(5);
    ll.display();
    ll.head = reverseLL(ll.head);
    ll.display();

    linkedList ll2;
    ll2.insertAtTail(6);
    ll2.insertAtTail(7);
    ll2.insertAtTail(8);
    ll2.insertAtTail(9);
    ll2.insertAtTail(10);
    ll2.display();
    ll2.head = recursive_reverseLL(ll2.head);
    ll2.display();

}