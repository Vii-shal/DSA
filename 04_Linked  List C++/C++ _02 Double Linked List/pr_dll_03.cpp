// delete node if there neighbour is same 
// 2<->1<->1<->2<->1
// 2<->1<->1

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

void deleteNodeIfNeighbourSame(node * &head,node *&tail){
    node *currNode = tail->prev;
    while(currNode != head){
        node * preNode = currNode->prev;
        node * nextNode = currNode->next;
        if (preNode->val == nextNode->val){
            preNode->next = nextNode;
            nextNode->prev = preNode;
            free(currNode);
        }
        currNode = preNode;
    }
}


int main(){
    doublyLinkedList dll;
    dll.insertAtEnd(1);
    dll.insertAtEnd(2);
    dll.insertAtEnd(1);
    dll.insertAtEnd(2);
    dll.insertAtEnd(1);
    dll.display();
    deleteNodeIfNeighbourSame(dll.head,dll.tail);
    dll.display();
}