// given a binary tree , print the level order in reverse manner 
// i.e print the last row first and then the rows below.

#include<iostream>
#include<vector>
#include<queue>
#include<stack>
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

vector<int> reverseLevelOrder(node* root){
    vector <int> ans;
    if (root==NULL)  return ans;
    queue<node *> q;
    stack<node*> s;
    q.push(root);

    while (!q.empty()){
        int nodesAtCurrLevel = q.size();
        while (nodesAtCurrLevel--){
            node *currNode=q.front();
            q.pop();
            s.push(currNode);
            if (currNode->right){
                q.push(currNode->right);
            }
            if (currNode->left){
                q.push(currNode->left);
            }
        }
    }
    while(!s.empty()){
        ans.push_back(s.top()->val);
        s.pop();
    }
    return ans;
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
    vector<int> v = reverseLevelOrder(root);
    for (auto ele:v){
        cout<<ele<<"  ";
    }

}



//       2
//     4   10
//   6  5    11
// 33           