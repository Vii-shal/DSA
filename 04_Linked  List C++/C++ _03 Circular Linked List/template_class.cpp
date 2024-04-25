#include<iostream>
using namespace std;

template <typename T>
class node{                      // template class
    public:
    T val;
    node * next;

    node(T value){
        val =value ;
        next = NULL;
    }

};

int main(){
    node<int>* node1 = new node<int> (3);
    
    cout<<node1->val<<endl;

    node<char>* node2 = new node<char> ('&');
    cout<<node2->val<<endl;

}