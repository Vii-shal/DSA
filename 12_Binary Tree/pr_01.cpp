// find the maximum depth ,is the number of nodes along the longest path from the root node down to the farthest leaf node .

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

int maxDepth(node* rootNode){
    if (rootNode == NULL){
        return 0;
    }
    // recursivr case
    int leftdepth = maxDepth(rootNode->left);
    int rightdepth = maxDepth(rootNode->right);
    return max(leftdepth,rightdepth) +1;
}

int main(){
    node*root = new node(2);
    root->left = new node(4);
    root->right = new node(10);
    root->left->left = new node(6);
    root->left->right = new node(5);
    root->right->right = new node(11);
    root->right->right->right = new node(12);
    cout<<maxDepth(root);

}



//     2
//   4   10
// 6  5    11
//           12