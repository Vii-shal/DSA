// given the root of a binary tree , imagine yourself standing on the right side of it ,
// return the values of the nodes you can see from top to bottom . .

#include<iostream>
#include<vector>
#include<queue>
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

vector<int> rightViewBinaryTree(node* root){
    vector<int> res;
    if (root==NULL) return res;

    queue <node*> q;
    q.push(root);

    while (!q.empty()){
        int nodesAtCurrLevel = q.size();
        while (nodesAtCurrLevel){
            node *currNode = q.front();
            q.pop();

            if (nodesAtCurrLevel == 1){
                res.push_back(currNode->val);
            }
            if (currNode->left){
                q.push(currNode->left);
            }
            if (currNode->right){
                q.push(currNode->right);
            }
            nodesAtCurrLevel--;
        }
    }
    return res;

}

int main(){
    node*root = new node(2);
    root->left = new node(4);
    root->right = new node(10);
    root->left->left = new node(6);
    root->left->left->left = new node(33);
    root->left->right = new node(5);
    root->right->right = new node(11);
    // root->right->right->right = new node(12);
    vector<int> v = rightViewBinaryTree(root);
    for (auto ele:v){
        cout<<ele<<"  ";
    }

}



//       2
//     4   10
//   6  5    11
// 33           