// lowest commom ancestor
// a node can be ancestor of its own

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

node * lowestCommonAncestor(node * root,node * node1,node * node2){
    // base case
    if (root==NULL){
        return NULL;
    }

    if (root->val > node1->val && root->val > node2->val){
        // LCA will lie in left subtree
        return lowestCommonAncestor(root->left , node1 , node2);
    }
    if (root->val < node1->val && root->val < node2->val){
        // LCA will lie in right subtree
        return lowestCommonAncestor(root->right , node1 , node2);
    }
    // if root value lies betwwen node1 and node2 value
    // or if root value is equal to any of the values
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
   bst bst1;
   insertBST(bst1.root,3);
   insertBST(bst1.root,1);
   insertBST(bst1.root,4);
   insertBST(bst1.root,6);
   insertBST(bst1.root,2);

   node* node1 = new node(6);
   node* node2 = new node(4);
   node *temp = lowestCommonAncestor(bst1.root,node1,node2);
   cout<<temp->val;

}



//       3
//    1      4
//      2     6