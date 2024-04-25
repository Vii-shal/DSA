// find the node at which two linkedlist intersect .  
// 2 pointers problem

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

int getlength(node * head){
    node * temp = head;
    int length = 0;
    while (temp!=NULL){
        temp = temp->next;
        length++;
    }
    return length;
}

node *  moveHeadByK(node * head,int k){
    node * ptr = head;
    while(k--){
        ptr= ptr->next;
    }
    return ptr;
}

node * findIntersection(node *head1,node *head2){

    int l1=getlength(head1);
    int l2=getlength(head2);

    node* ptr1;          // like temp
    node* ptr2 ;
    if(l1>l2){
        int k = l1-l2;
        ptr1 = moveHeadByK(head1,k);
        ptr2 = head2;
    }
    else{
        int k = l2-l1;
        ptr1 = head1;
        ptr2 = moveHeadByK(head2,k);     
    }
    while(ptr1){
        if (ptr1 == ptr2){
            return ptr1;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return NULL;
}




int main(){
    linkedList ll;
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(4);
    ll.insertAtTail(5);
    // 1->2->3->4->5->NULL

    linkedList ll2;
    ll2.insertAtTail(6);
    ll2.insertAtTail(7);
    ll2.insertAtTail(4);
    ll2.insertAtTail(5);
    ll2.head->next->next = ll.head->next->next->next;
    // 6->7->4->5->NULL

    ll.display();
    ll2.display();
    node* intersection = findIntersection(ll.head,ll2.head);
    if (intersection){
        cout<<intersection->val;
    }
    else{
        cout<<-1;
    }

}