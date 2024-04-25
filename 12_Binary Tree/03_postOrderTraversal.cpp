// postOrderTraveral

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
    preOrderTraversal(rootNode->left);
    preOrderTraversal(rootNode->right);
    cout << rootNode->val<<" ";
}

int main(){
    Node*root = new Node(2);
    root->left = new Node(4);
    root->right = new Node(10);
    root->left->left = new Node(6);
    root->left->right = new Node(5);
    root->right->right = new Node(11);
    preOrderTraversal(root);

}



//     2
//   4   10
// 6  5    11