#include<iostream>
using namespace std;

class node{
    public:
    int val;
    node * prev;
    node * next;
    node(int value){
        val = value;
        prev = NULL;
        next = NULL;
    }
};

class DoubleLinkedList{
    public:
    node * head;
    node * tail;

    DoubleLinkedList(){
        head=NULL;
        tail=NULL;
    }

    void display(){
        node * temp = head;
        while (temp != NULL){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
    
    //--------------------INSERTION-------------------------------------------

    void insertAtStart(int value){
        node * new_node = new node(value);
        if (head == NULL){
            head = new_node;
            tail = new_node;
            return;
        }
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }

    void insertAtEnd(int value){
        node * new_node = new node(value);
        if (tail == NULL){
            head = new_node;
            tail = new_node;
            return ;
        }
        tail->next = new_node;
        new_node -> prev  =tail;
        tail = new_node;
    }

    void insertAtKthPos(int value , int k){
        
        // assuming k is less or equal to length of doubly linked list . 
        node * new_node = new node(value);
        node * temp = head;
        int curr=1;
        while (curr != k-1){
            temp = temp->next;
            curr++;
        }

        // temp will be pointing to the node at (k-1)th position 
        new_node->next = temp->next;
        temp->next = new_node; 

        new_node->prev = temp;
        new_node->next->prev = new_node;
    }


    //-------------------DELETION---------------------------------------------

    void deleteAtStart(){

        if (head == NULL){
            return;
        }

        node * temp = head;
        head = head->next;
        if (head == NULL){    // if doubly linked list had only 1 node 
            tail = NULL;
        }
        else{
            head->prev = NULL;
        }
        free(temp);
    }

    void deleteAtEnd(){

        if (head == NULL){
            return;
        }

        node * temp = tail;
        tail = tail->prev;
        if (tail == NULL){
            head = NULL;
        }
        else {
            tail -> next = NULL ;
        }
        free(temp);
    }

    void deleteAtKthPos(int k){
        
        // node * ptr = head;
        // int curr = 1;
        // while(curr<k-1){
        //     ptr = ptr->next;
        //     curr++;
        // }
        // node * temp = ptr->next;
        // ptr->next = ptr->next->next;
        // ptr->next->prev = ptr;
        // free(temp);

        node * temp = head;
        int count = 1;
        while (count<k){
            temp = temp->next;
            count++;
        }

        // now temp is pointing to kth node 
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
        
    }
};

int main(){
    DoubleLinkedList dll;
    dll.insertAtStart(10);
    dll.insertAtStart(20);
    dll.insertAtStart(30);
    dll.insertAtStart(40);
    dll.display();

    DoubleLinkedList dll2;
    dll2.insertAtEnd(1);
    dll2.insertAtEnd(2);
    dll2.insertAtEnd(3);
    dll2.display();
    
    dll2.insertAtKthPos(999,3); 
    dll2.display();


    DoubleLinkedList dll3;
    dll3.insertAtEnd(1);
    // dll3.insertAtEnd(2);
    // dll3.insertAtEnd(3);
    // dll3.insertAtEnd(4);
    // dll3.insertAtEnd(5);
    dll3.display();
    dll3.deleteAtStart();
    dll3.display();
    dll3.insertAtEnd(5);
    dll3.display();
    dll3.deleteAtEnd();
    dll3.display();

    dll3.insertAtEnd(1);
    dll3.insertAtEnd(2);
    dll3.insertAtEnd(3);
    dll3.insertAtEnd(4);
    dll3.insertAtEnd(5);
    dll3.insertAtEnd(6);
    dll3.insertAtEnd(7);
    dll3.display();
    dll3.deleteAtStart();
    dll3.display();
    dll3.deleteAtEnd();
    dll3.display();
    dll3.deleteAtKthPos(2);
    dll3.display();
}