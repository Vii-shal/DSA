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

class BST{
    public:
    node *root;
    BST(){
        root=NULL;
    }


};

// insertion normal way  // iterative way
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

// insertion recursive way
node* insertRecursiveBST(node * &root, int v){
    // base case
    if (root==NULL){
        node* newNode = new node(v);
        return newNode;
    }

    // recursive case 
    if (v < root->val){
        root->left = insertRecursiveBST(root->left , v);
    }
    else if (v > root->val){
        root->right = insertRecursiveBST(root->right , v);
    }
    return root;

}

// Search
bool searchBST(node * &root, int v){
    if (root==NULL){
        return false;
    }
    if (root->val == v){
        return true;
    }
    // recursive case
    if (v < root ->val){
        return searchBST(root->left,v);
    }
    if (v > root ->val){
        return searchBST(root->right,v);
    }
}


// Deletion
node* largestNodeBST(node* root){        
    node * curr = root;
    while(curr && curr->right != NULL){
        curr = curr->right;
    }
    return curr;
}

node* deleteBST(node * &root,int key){
    if  (root==NULL){
        return root;
    }

    if (root->val < key){
        root->right = deleteBST(root->right,key);
    } 
    else if (root->val > key){
        root->left = deleteBST(root->left,key);
    } 
    else{  // root is the node to be deleted or finded the key node to be deleted
        if (root->left==NULL && root->right==NULL){ //node has 0 child
            free(root);
            return NULL;
        }
        else if (root->left==NULL){                // node has 1 child
            node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right==NULL){                // node has 1 child
            node* temp = root->left;
            free(root);
            return temp;
        }
        else {                               // node has two children
            node* justSmallerNode = largestNodeBST(root->left);
            root->val = justSmallerNode->val;
            root->left = deleteBST(root->left,justSmallerNode->val);
        }
    }
    return root;

}

// Traversal
void inorderTraversal(node * root){
    if(!root) return;
    inorderTraversal(root->left);
    cout<<root->val<<"  ";
    inorderTraversal(root->right);
}

int main(){
    BST bst1;
    insertBST(bst1.root,3);
    insertBST(bst1.root,1);
    insertBST(bst1.root,4);
    insertBST(bst1.root,6);
    insertBST(bst1.root,2);

    inorderTraversal(bst1.root);
    cout<<endl;

    BST bst2;
    bst2.root = insertRecursiveBST(bst2.root,3);
    insertRecursiveBST(bst2.root,1);
    insertRecursiveBST(bst2.root,4);
    insertRecursiveBST(bst2.root,6);
    insertRecursiveBST(bst2.root,2);

    inorderTraversal(bst2.root);
    cout<<endl;

    cout<<searchBST(bst2.root,3)<<endl;
    cout<<searchBST(bst2.root,8)<<endl;

    // delete
    bst2.root = deleteBST(bst1.root,1);
    inorderTraversal(bst2.root);
    cout<<endl;

}


//   3
// 1   4
//  2   6