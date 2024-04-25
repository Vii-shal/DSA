
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

bool isCriticalPoint(node * currNode){
    if (currNode->prev->val > currNode->val  && currNode->next->val > currNode->val){      //local minima
        return true;
    }
    if (currNode->prev->val < currNode->val  && currNode->next->val < currNode->val){      //local maxima
        return true;
    }
    return false;
}

vector<int> distanceBetweenCriticalPoints(node * tale){
    vector <int> ans(2,INT16_MAX);
    int firstCP = -1  , lastCP = -1;

    node * currNode = tale->prev;
    if (currNode == NULL){
        ans[0] = ans[1] = -1;
        return ans;
    }
    int currpos = 0;
    while(currNode->prev != NULL){
        if (isCriticalPoint(currNode)){
            if(firstCP == -1){
                firstCP = lastCP = currpos;
            }
            else{
                ans[0] = min(ans[0],currpos - lastCP);      // min distance
                ans[1] = currpos - firstCP;                 // max distance
                lastCP = currpos;
            }
        }
        currpos++;
        currNode = currNode->prev;
    }

    if (ans[0] == INT16_MAX){
        ans[0] = ans[1] = -1;
    }
    return ans;

}


int main(){
    doublyLinkedList dll;
    dll.insertAtEnd(1);
    dll.insertAtEnd(5);

    dll.insertAtEnd(2);
    dll.insertAtEnd(6);
    dll.insertAtEnd(3);
    dll.display();
    vector <int> result = distanceBetweenCriticalPoints(dll.tail);
    cout<<result[0]<<"  "<<result[1]<<endl;

    doublyLinkedList dll2;
    dll2.insertAtEnd(1);
    dll2.insertAtEnd(5);
    dll2.insertAtEnd(4);
    dll2.insertAtEnd(2);
    dll2.insertAtEnd(6);
    dll2.insertAtEnd(3);
    dll.display();
    vector <int> result2 = distanceBetweenCriticalPoints(dll2.tail);
    cout<<result2[0]<<"  "<<result2[1]<<endl;
}