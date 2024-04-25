#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class node{
    public:
    char data;
    vector<node*> children;

    node(char data){
        this->data = data;
    }
};


void preorderTraversal(node *root){
    if (root == NULL)  return ;
    cout << root->data << " ";
    for (node* child : root->children){
        preorderTraversal(child);
    }
    return;
}

void postorderTraversal(node *root){
    if (root == NULL)  return ;
    for (node* child : root->children){
        postorderTraversal(child);
    }
    cout << root->data << " ";
    return;
}

void inorderTraversal(node *root){
    if (root == NULL)  return ;

    int childNodes = root->children.size();
    for (int i=0;i<childNodes-1;i++){
        inorderTraversal(root->children[i]);
    }
    cout << root->data << " ";
    if (childNodes > 0){
        inorderTraversal(root->children[childNodes-1]);
    }
    return;
}

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

int main(){

    node* root = new node('A');
    root->children.push_back(new node('B'));
    root->children.push_back(new node('C'));
    root->children.push_back(new node('D'));
    root->children[0]->children.push_back(new node('E'));
    root->children[0]->children.push_back(new node('F'));
    root->children[2]->children.push_back(new node('G'));

    preorderTraversal(root);
    cout<<endl;
    postorderTraversal(root);
    cout<<endl;
    inorderTraversal(root);
    cout<<endl;
    bfs(root);
}


//             A
//      B      C      D
//    E   F         G