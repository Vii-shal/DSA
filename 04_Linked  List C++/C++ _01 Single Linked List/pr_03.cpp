// remove kth element from end , and display LL .

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

node*  removeKthFromEnd(node* head,int k){
    node * ptr1 = head;
    node * ptr2 = head;
    while (k--){
        ptr2 = ptr2->next;
    }
    if (ptr2 == NULL){        // k is equal to the length of LL   // head node deleted
        node * temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    while (ptr2->next != NULL){
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    node * temp = ptr1->next;
    ptr1->next = ptr1->next->next;
    free(temp);
    return head;

}




int main(){
    linkedList ll;
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(4);
    ll.insertAtTail(5);
    ll.display();
    ll.head = removeKthFromEnd(ll.head,5);
    ll.display();


}