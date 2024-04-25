// You are given the head of linkedList . 
// L0->L1->L2->....->Ln-1 ->Ln
// L0->Ln->L1->Ln-1 ->L2->Ln-2.....


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

node * reorderLinkedList(node * &head){
    // find middle of linkedList 
    node * s = head;
    node * f = head;
    while (f && f->next){
        s = s->next;
        f = f->next->next;
    }
    // reverse second half 
    node * curr = s->next;
    s->next = NULL;
    node * pre = s;
    while (curr != NULL){
        node * nextptr = curr->next;
        curr->next = pre;
        pre = curr;
        curr = nextptr;
    }
    node * h1 = head;
    node * h2 = pre;
    // combine
    while (h1!=h2){
        node * temp = h1->next;
        h1->next = h2;
        h1 = h2;
        h2 = temp;
    }
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

    reorderLinkedList(ll.head);
    ll.display();
    
}