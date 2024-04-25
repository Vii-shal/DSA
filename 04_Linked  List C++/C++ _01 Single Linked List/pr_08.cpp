// is palendrome 

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

bool isPalendrome(node* &head){

    // 1. find middle element
    node *slow = head;
    node *fast = head;

    while (fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    // now slow is pointing to middle element 
    // 2. break the linked list in the middle
    node *curr = slow->next;
    node * pre = slow;
    slow->next = NULL;

    // 3. reverse the second half of the linked list
    while (curr){
        node * next = curr->next;
        curr->next = pre;
        pre = curr;
        curr = next;
    }

    // 4. check if the two linked lists are equal
    node * head2 = pre;
    node * head1 = head;
    while (head2){
        if (head1->val != head2->val){
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return true;
}



int main(){
    linkedList ll;
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(5);
    ll.insertAtTail(5);
    ll.insertAtTail(3);
    ll.insertAtTail(2);
    ll.insertAtTail(1);
    ll.display();
 

    cout<<isPalendrome(ll.head);
}