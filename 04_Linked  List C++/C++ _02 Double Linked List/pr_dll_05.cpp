
#include<iostream>
#include<vector>
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
        else{

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        }
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

vector <int> sumEqualToX(node * head,node* tail , int x){
    vector<int> ans(2,-1);
    
    while (head != tail){
        int sum = head->val + tail->val;
        if (sum == x){
            ans[0] = head->val;
            ans[1] = tail->val;
            return ans;
        }
        if (sum < x){
            head = head->next;
        }
        else{
            tail = tail->prev;
        }
    }  
    return ans;
}


int main(){
    doublyLinkedList dll;
    dll.insertAtEnd(1);
    dll.insertAtEnd(2);  
    dll.insertAtEnd(4);
    dll.insertAtEnd(5);
    dll.insertAtEnd(6);
    dll.display();

    vector<int> ans = sumEqualToX(dll.head,dll.tail,7);
    cout<<ans[0]<<" "<<ans[1]<<endl;
}