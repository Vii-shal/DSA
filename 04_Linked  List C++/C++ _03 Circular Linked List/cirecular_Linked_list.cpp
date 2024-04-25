#include<iostream>
using namespace std;

class node{
    public:
    int val;
    node* next;
    node(int value){
        val = value;
        next = NULL;
    }
};

class circularLinkedList{
    public :
    node * head;
    circularLinkedList(){
        head = NULL;
    }

    void insertAtStart(int value){                         // O(n)
        node * new_node = new node(value);
        if (head == NULL){
            head = new_node;
            new_node->next = head;                        // circular linked list
            return;
        }
        node * tail = head;
        while (tail->next != head){
            tail = tail->next;
        }
        tail->next = new_node;
        new_node->next = head;
        head = new_node;
    }

    void insertAtEnd(int value){           // O(n)
        node * new_node = new node(value);
        if (head == NULL){
            head = new_node;
            new_node->next = head;        //circular linked list
            return;
        }
        node * tail = head;
        while (tail->next != head){
            tail = tail->next;
        }
        tail->next = new_node;
        new_node->next= head ;
    }

    void insertAtKthPos(int value,int k){
        node * new_node = new node(value);
        node * currPtr = head;
        int curr = 1;
        while(curr<k-1){
            currPtr = currPtr->next;
            curr++;
        }
        node*  temp = currPtr->next;
        currPtr->next = new_node;
        new_node->next = temp;
    }

    void deleteAtStart(){
        node *temp = head;
        node * tail = head;
        while (tail->next != head){
            tail = tail->next;
        }
        tail->next = head->next;
        head = head->next;
        free(temp);
    }

    void deleteAtEnd(){
        node * tail = head;
        while(tail->next->next != head){
            tail = tail->next;
        }
        node* temp = tail->next;
        tail->next = head;
        free(temp);
    }

    void deleteAtK(int k){
        node * nodePtr = head;
        int curr = 1;
        while (curr<k-1){
            nodePtr = nodePtr->next;
            curr++;
        }
        node * temp = nodePtr->next;
        nodePtr->next = nodePtr->next->next;
        free(temp);
    }

    void printCircular(){
        node * temp = head;
        for (int i=0;i<20;i++){
            cout<<"->"<<temp->val;
            temp = temp->next;
        }
    }
    
    void display(){
        node * temp =  head;
        do{
            cout << "->"<<temp->val;
            temp = temp->next;
        }while (temp != head);
        cout<<endl;
    }
};





int main(){
    circularLinkedList cll;
    cll.insertAtStart(1);
    cll.insertAtStart(2);
    cll.insertAtStart(3);
    cll.insertAtStart(4);
    cll.insertAtStart(5);
    cll.display();

    circularLinkedList cll2;
    cll2.insertAtEnd(6);
    cll2.insertAtEnd(7);
    cll2.insertAtEnd(8);
    cll2.insertAtEnd(9);
    cll2.insertAtEnd(10);
    cll2.display();

    circularLinkedList cll3;
    cll3.insertAtEnd(11);
    cll3.insertAtEnd(12);
    cll3.insertAtEnd(13);
    cll3.insertAtEnd(14);
    cll3.insertAtEnd(15);
    cll3.insertAtKthPos(22,2);
    cll3.display();
    cll3.deleteAtStart();
    cll3.display();
    cll3.deleteAtEnd();
    cll3.display();
    cll3.deleteAtK(2);
    cll3.display();
    // cll3.printCircular();            //check circular or not .

}