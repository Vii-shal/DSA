// stack implementaion through array 

#include<iostream>
using namespace std;

class stack{
    int capacity;
    int* arr;
    int top;

    public:
    stack(int c){
        this->capacity =c ;
        this->arr=new int[c];
        this->top = -1;
    }

    // All functions are in O(1)  time complexity 

    void push(int val){                                       // (1)
        if (this->top == this->capacity - 1){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        this->top ++;
        this->arr[this->top] = val;
    }

    int pop(){                                                // (2)
        if (this->top == -1){
            cout<< "stack underflow"<<endl;
            return INT16_MIN;
        }
        this->top --;
    }

    int getTop(){                                                // (3)
        if (this->top == -1){
            cout<< "stack underflow"<<endl;
            return INT16_MIN;
        }
        return this->arr[this->top];
    }

    int size(){                                               // (4)
        return this->top+1;
    }

    bool isFull(){                                            // (5)
        return this->top == this->capacity-1;
    }

    bool isEmpty(){                                           // (6)
        return this->top == -1;
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