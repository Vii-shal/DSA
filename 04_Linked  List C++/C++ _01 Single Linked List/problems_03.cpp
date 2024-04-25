// given the head of a linked list , delete every alternate element from second element .
// given the head of a sorted linked list , delete all duplicates such that each element appears only once . return the linked list sorted as well .
// given the head of a singly linked list and print the reversed list .


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


// deleting alternate nodes 
void delAlternate(node *&head){
    node * curr_node = head;
    while (curr_node != NULL  && curr_node->next != NULL){
        node* temp = curr_node->next;
        curr_node->next = curr_node->next->next;
        free(temp);
        curr_node = curr_node->next;
    }
}

// delete duplicate values
void delDuplicate(node*&head){
    node * curr_node = head;
    // while (curr_node != NULL){
    while (curr_node){
        while (curr_node->next != NULL   &&   curr_node->val == curr_node->next->val){
            node * temp = curr_node->next;
            curr_node->next = curr_node->next->next;
            free(temp);
        }
        curr_node = curr_node->next;
    }
}

// traverse in reverse order 
void revTraversal(node * head){
    // base case
    if (head == NULL) return;
    // recursive case 
    revTraversal(head->next);
    cout<<head->val<<" ";
}


int main(){
    linkedList li1;
    li1.insertAtTail(1);
    li1.insertAtTail(2);
    li1.insertAtTail(3);
    li1.insertAtTail(4);
    li1.insertAtTail(5);
    li1.insertAtTail(6);
    li1.display();

    delAlternate(li1.head);
    li1.display();


    linkedList li2;
    li2.insertAtTail(1);
    li2.insertAtTail(2);
    li2.insertAtTail(2);
    li2.insertAtTail(2);
    li2.insertAtTail(5);
    li2.insertAtTail(5);
    li2.display();

    delDuplicate(li2.head);
    li2.display();


    linkedList li3;
    li3.insertAtTail(1);
    li3.insertAtTail(2);
    li3.insertAtTail(3);
    li3.insertAtTail(4);
    li3.insertAtTail(5);
    li3.insertAtTail(6);
    li3.display();

    revTraversal(li3.head);
    

}