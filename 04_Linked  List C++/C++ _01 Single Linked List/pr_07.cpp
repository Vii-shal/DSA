// tell cycle is present in linkedList or not 

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

bool checkCycle(node * head){
    node * fast = head;
    node * slow = head;
    if (!head){
        return false;
    }
    while (fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast){
            cout<<slow->val<<endl;      // where slow and fast meet
            return true;
        }
    }
    return false;
}

// removing cycle 
void removeCycle(node * &head){      // assuming linked list have cycle
    node * slow = head;
    node * fast = head;

    do{
        slow = slow->next;
        fast = fast->next->next;
    }while(slow != fast);

    fast = head;
    while(slow->next != fast->next){
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = NULL;
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
    ll.head->next->next->next->next->next->next->next->next = ll.head->next->next; 

    cout<<checkCycle(ll.head)<<endl;
    removeCycle(ll.head);
    cout<<endl<<"after removing cycle"<<endl;
    cout<<checkCycle(ll.head)<<endl;
    ll.display();
}