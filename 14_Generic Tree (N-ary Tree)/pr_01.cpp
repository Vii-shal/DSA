// Given a generic tree and an integer x. Find and return the node with the next larger elements 
// i.e. find a node just greater than x.

#include<iostream>
#include<vector>
#include<queue>
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

void justGreatest(node* root,int x,node * &ans){
    if (root == NULL){
        return ;
    }

    if (root->data >x && (ans==NULL || root->data < ans->data)){
        ans=root;
    }
    for (node* child:root->children){
        justGreatest(child,x,ans);
    }
}

int main(){
    node* root = new node(20);
    root->children.push_back(new node(8));
    root->children.push_back(new node(22));
    root->children[0]->children.push_back(new node(4));
    root->children[0]->children.push_back(new node(12));
    root->children[0]->children[1]->children.push_back(new node(10));
    root->children[0]->children[1]->children.push_back(new node(14));
    bfs(root);

    node*ans = NULL;
    int x=10;
    justGreatest(root,x,ans);
    cout<<"ans :"<<endl;
    if (ans!=NULL){
        cout<<ans->data<<endl;
    }
    else{
        cout<<"NULL"<<endl;
    }


}


//           20
//      8            22
//   4     12
//        10 4