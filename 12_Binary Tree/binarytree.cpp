#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;
    Node(int value){
        val = value;
        left = NULL;
        right = NULL;
    }
};

void preOrderTraversal(Node * &rootNode){
    if (rootNode == NULL){
        return;
    }
    cout << rootNode->val<<" ";
    preOrderTraversal(rootNode->left);
    preOrderTraversal(rootNode->right);
}

int main(){
    Node*root = new Node(2);
    root->left = new Node(4);
    root->right = new Node(10);
    cout<<"Root node: "<<root->val<<endl;
    cout<<"Left child: "<<root->left->val<<endl;
    cout<<"Right child: "<<root->right->val<<endl;
}
