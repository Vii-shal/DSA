// ionorder predecessor and successor

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

void inorderPreSuccBST(node *root,node *&pre,node* &succ,int key){
    if (root == NULL) return;

    if (root->val == key){
        // pre -> rightmost node in left subtree
        if (root->left != NULL){
            node *temp = root->left;
            while (temp->right != NULL) {
                temp=temp->right;
            }
            pre = temp;
        }
        // succ -> leftmost node in right subtree
        if (root->right!=NULL){
            node *temp = root->right;
            while (temp->left != NULL) {
                temp = temp->left;
            }
            succ = temp;
        }
        return;
    }
    if (root->val > key){
        succ = root;
        inorderPreSuccBST(root->left , pre,succ,key);
    }
    else if(root->val < key){
        pre = root;
        inorderPreSuccBST(root->right , pre,succ,key);
    }

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

    node* pre = NULL;
    node* succ = NULL;
    inorderPreSuccBST(bst1.root,pre,succ,1);

    if (pre!=NULL){
        cout<<"pre - "<<pre->val<<endl;
    }
    else{
        cout<<"pre - NULL";
    }
    cout<<endl;
    if (succ!=NULL){
        cout<<"succ - "<<succ->val<<endl;
    }
    else{
        cout<<"succ - NULL";
    }
}



//       3
//    1      4
//      2     6