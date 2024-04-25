// Calculate number of leaf tree .

#include<iostream>
using namespace std;

class node{
    public:
    int val;
    node* left;
    node* right;
    node(int value){
        val = value;
        left = NULL;
        right = NULL;
    }
};

int leafNode(node* root){
    // base case
    if (root == NULL){
        return 0;
    }
    if (root->left==NULL && root->right==NULL){
        return 1;
    }
    // recursive case
    int leftSubTreeleafNode = leafNode(root->left);
    int rightSubTreeleafNode = leafNode(root->right);
    return (leftSubTreeleafNode + rightSubTreeleafNode);
}

int main(){
    node*root = new node(2);
    root->left = new node(4);
    root->right = new node(10);
    root->left->left = new node(6);
    root->left->right = new node(5);
    root->right->right = new node(11);
    root->right->right->right = new node(12);

    cout<<leafNode(root);
}



//     2
//   4   10
// 6  5    11
//           12
