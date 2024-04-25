// Mirror Tree

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

class node{
    public:
    int data;
    vector<node*> children;

    node(int data){
        this->data = data;
    }
};

void bfs(node * root){
    if (root==NULL) return;
    queue <node*> q;
    q.push(root);
    
    while(!q.empty()){
        int childNodes = q.size();
        while (childNodes--){

            //dequeue
            node * curr = q.front();
            q.pop();
            cout<<curr->data<<" ";

            //enqueue all child nodes
            for (node* child: curr->children){
                q.push(child);
            }
        }
        cout<<endl;
    }
}

void mirrorTree(node* &root){
    if (root == NULL){
        return ;
    }
    if (root->children.size() < 2){
        return;
    }
    reverse(root->children.begin(),root->children.end());
    for (node* child:root->children){
        mirrorTree(child);
    }
}

int main(){
    node* root = new node(10);
    root->children.push_back(new node(2));
    root->children.push_back(new node(34));
    root->children.push_back(new node(56));
    root->children.push_back(new node(100));
    root->children[1]->children.push_back(new node(1));
    root->children[3]->children.push_back(new node(7));
    root->children[3]->children.push_back(new node(8));
    root->children[3]->children.push_back(new node(9));
    bfs(root);
    mirrorTree(root);
    cout<<"mirror Tree"<<endl;
    bfs(root);

}


//           10
//    2    34    56    100
//          1          7 8 9