#include<iostream>
#include<vector>
using namespace std;

class node{
    public:
    char data;
    vector<node*> children;

    node(char data){
        this->data = data;
    }
};


int main(){
    node* root = new node('A');
    root->children.push_back(new node('B'));
    root->children.push_back(new node('C'));

    cout<<root->data<<endl;
    cout<<"printing child nodes of parent A"<<endl;
    for (node* child:root->children){
        cout <<child->data<<" ";
    }

}