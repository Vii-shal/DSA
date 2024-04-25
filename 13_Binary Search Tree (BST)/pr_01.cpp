// sorted array to BST

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

node* arrayToBst(vector<int> &v,int first,int last){
    // base case 
    if (first > last){
        return NULL;
    }
    int mid = first + (last-first)/2;
    node *root = new node(v[mid]);
    root->left = arrayToBst(v,first,mid-1);
    root->right = arrayToBst(v,mid+1,last);
    return root;
}

void preorderTraversal(node * root){
    // cout<<"hello";
    if(!root) return;
    cout<<root->val<<"  ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main(){
    vector<int> v = {1,2,3,4,5,6,7,8};
    bst t;
    t.root = arrayToBst(v,0,v.size()-1);
    preorderTraversal(t.root);
}