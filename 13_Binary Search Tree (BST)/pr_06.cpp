// replace element in an array with just greatest element/number.

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

node * insertNode(node* root,int element,int &successor){
    if (root==NULL){
        return new node(element);
    }
    if (element<root->val){
        successor=root->val;
        root->left = insertNode(root->left,element,successor);
    }
    else if (element>root->val){
        root->right = insertNode(root->right,element,successor);
    }
    return root;
}

void replaceWithLeastGreatestElement(vector<int> &v){
    node * root = NULL;

    for (int i=v.size()-1;i>=0;i--){
        int successor = -1;
        root = insertNode(root,v[i],successor);
        v[i] = successor;
    }
}


int main(){
    vector<int> v={8,3,10,1,6,9,14};
    replaceWithLeastGreatestElement(v);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }

}


