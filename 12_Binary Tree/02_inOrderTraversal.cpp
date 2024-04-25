// inorderTraversal 

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

void inOrderTraversal(Node * &rootNode){
    if (rootNode == NULL){
        return;
    }
    inOrderTraversal(rootNode->left);
    cout << rootNode->val<<" ";
    inOrderTraversal(rootNode->right);
}

int main(){

    Node*root = new Node(2);
    root->left = new Node(4);
    root->right = new Node(10);
    root->left->left = new Node(6);
    root->left->right = new Node(5);
    root->right->right = new Node(11);
    inOrderTraversal(root);

}



//     2
//   4   10
// 6  5    11