// given a binary tree .print the top view of the binary tree . 
// top view of the binary tree is the set of nodes visible when the tree is viewed from the top .

#include<iostream>
#include<vector>
#include<queue>
#include<map>
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

vector<int> topViewBinaryTree(node* root){
    vector<int> res;
    if (root==NULL) return res;

    queue<pair<node*,int>> q;
    q.push(make_pair(root,0));
    map<int,int> m;

    while(!q.empty()){
        int nodeAtCurrLevel = q.size();
        while(nodeAtCurrLevel--){
            pair<node*,int> p = q.front();
            node * currNode = p.first;
            int currCol = p.second; 
            q.pop();

            if (m.find(currCol) == m.end()){
                m[currCol] = currNode->val;
            }
            if (currNode->left){
                q.push(make_pair(currNode->left , currCol-1));
            }
            if (currNode->right){
                q.push(make_pair(currNode->right , currCol+1));
            }
        }
    }
    for (auto it:m){
        res.push_back(it.second);
    }
}

int main(){
    node*root = new node(2);
    root->left = new node(4);
    root->right = new node(10);
    root->left->left = new node(6);
    root->left->left->right = new node(33);
    root->left->right = new node(5);
    root->right->right = new node(11);
    // root->right->right->right = new node(12);
    vector<int> ans = topViewBinaryTree(root);
    for (auto v:ans){
        cout<<v<<" ";
    }


}



//       2
//     4   10
//   6  5    11
//    33           