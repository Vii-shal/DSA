// remove leaf nodes

#include<iostream>
#include<vector>
using namespace std;

class node{
    public:
    int val;
    node *left;
    node *right;
    node (int v){
        val = v;
        left = NULL;
        right = NULL;
    }
};

class bst{
    public:
    node *root;
    bst(){
        root = NULL;
    }
};

void insertBST(node * &root,int v){
    node * newNode = new node(v);
    if (root == NULL) {
        root = newNode;
        return;
    }
    node * currNode = root;

    while (true){
        if (v < currNode->val){
            if (currNode->left == NULL){
                currNode->left = newNode;
                return;
            }    
            currNode = currNode->left;
        }
        else {
            if (currNode->right == NULL){
                currNode->right = newNode;
                return;
            }
            currNode = currNode->right;       
        }
    }
}

node* removeLeafNodes(node * root){
    if (root==NULL) return NULL;
    if (root->left == NULL && root->right ==NULL){
        return NULL;
    }
    root->left = removeLeafNodes(root->left);
    root->right = removeLeafNodes(root->right);
    return root;
}

void preorderTraversal(node * root){
    if(!root) return;
    cout<<root->val<<"  ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main(){
   bst bst1;
   insertBST(bst1.root,3);
   insertBST(bst1.root,1);
   insertBST(bst1.root,4);
   insertBST(bst1.root,6);
   insertBST(bst1.root,2);
   preorderTraversal(bst1.root);
   cout<<endl;

   removeLeafNodes(bst1.root);
   preorderTraversal(bst1.root);

}



//       3
//    1      4
//      2     6