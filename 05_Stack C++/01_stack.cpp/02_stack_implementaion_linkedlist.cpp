#include<iostream>
using namespace std;

class node{
    public:
    int val;
    node * next;
    node(int value){
        this->val=value;
        this->next = NULL;
    }
};

class stack{
    private:
    int capacity;
    node * head;
    int currSize;

    public:
    stack(int c){
        this->capacity = c;
        this->currSize = 0;
        head = NULL; 
    }

    // All have 0(1) time complexity

    void push(int data){                                       // (1)
        if  (this->currSize == this->capacity){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        node * new_node = new node(data);
        new_node->next = this->head;
        this->head = new_node;
        currSize++;
    }

    int pop(){                                                // (2)
        if (this->head == NULL){
            cout << "Underflow" << endl ;
            return INT16_MIN;
        }
        node * temp = head;
        int deletedVal = temp->val; 
        this->head = this->head->next;
        free(temp);
        currSize--;
        return deletedVal;
    }

    int size(){                                               // (3)
        return this->currSize;
    }

    int getTop(){                                             // (4)
        return this->head->val;
    }

    bool isEmpty(){                                           //(5)
        return this->head == NULL;
    }

    bool isFull(){                                            // (6)
        return (this->currSize == this->capacity);
    }
};

int main(){
    stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    cout<<st.getTop()<<endl;
    st.push(4);
    st.push(5);
    cout<<st.getTop()<<endl;
    st.push(8);

    st.pop();
    st.pop();
    cout<<st.getTop()<<endl;
    

}