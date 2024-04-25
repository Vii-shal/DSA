// check palendrome  

#include<iostream>
using namespace std;

class node{
    public:
    int val;
    node * next;
    node * prev;
    node(int value){
        val = value;
        next = NULL;
        prev = NULL;
    }
};

class doublyLinkedList{
    public:
    node* head, *tail ;
    doublyLinkedList(){
        head = NULL;
        tail = NULL;
    }

    void insertAtEnd(int value){
        node* newNode=new node (value);
        if (head==NULL){
            head = newNode;
            tail = newNode;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void display(){
        node * temp = head;
        while (temp != NULL){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

};

bool checkPalendrome(node *&head,node *&tail){
    while(head != tail  && tail != head->prev){
        if (head->val != tail->val){
            return false;
        }
        head = head->next;
        tail = tail->prev;
    }
    return true;
}

int main(){
    doublyLinkedList dll;
    dll.insertAtEnd(1);
    dll.insertAtEnd(2);
    dll.insertAtEnd(3);
    dll.insertAtEnd(3);
    dll.insertAtEnd(2);
    dll.insertAtEnd(1);
    dll.display();
    cout<<checkPalendrome(dll.head,dll.tail)<<endl;
    dll.display();
}