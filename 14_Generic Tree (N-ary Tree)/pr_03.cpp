// serialisation and deserialisation

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<unordered_map>
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

// serialisation
void serialiseTree(node * root,string &ans){
    if (root==NULL){
        return;
    }
    ans += to_string(root->data) + ":" + to_string(root->children.size()) + ":";
    for (node* child:root->children){
        ans+=to_string(child->data) + ",";
    }
    if(root->children.size()) ans.pop_back();         // to remove last comma
    ans+="\n";
    for (node* child: root->children){
        serialiseTree(child,ans);
    }
}


node* deserialiseTreeHelper(int nodeValue , unordered_map<int,string> mp){
    node* rootnode = new node(nodeValue);
    string nodeStr = mp[nodeValue];    // "2:30,40"
    if (nodeStr[0] == '0'){
        // leaf node 
        return rootnode;
    }
    int breakPos = nodeStr.find(':');
    int childNodeNumber = stoi(nodeStr.substr(0,breakPos));
    string childNodesStr = nodeStr.substr(breakPos+1); // "30,40"

    int start =0;
    for (int i=0;i<childNodeNumber;i++){
        int end = childNodesStr.find(',',start);
        if (end == string::npos) end = childNodesStr.size();
        int childNodeVal = stoi(childNodesStr.substr(start,end));
        rootnode->children.push_back(deserialiseTreeHelper(childNodeVal,mp));
        start = end+1;
    }
    return rootnode;
}


node* deserialiseTree(string serialisedStr){
    if (serialisedStr == ""){
        return NULL;
    }

    unordered_map<int,string> mp; // nodevalue -> childnodesstring
    int start = 0;
    for (int i=0;i<serialisedStr.size();i++){
        if (serialisedStr[i]=='\n'){
            string nodeStr = serialisedStr.substr(start,i-start);  //10:2:30,40
            int breakpos1 = nodeStr.find(':');
            int nodeValue = stoi(nodeStr.substr(0,breakpos1));    //10
            mp[nodeValue] = nodeStr.substr(breakpos1 + 1);               // "2:30,40"
            start = i+1;
        }
    }

    int rootNodeValue = stoi(serialisedStr.substr(0,serialisedStr.find(':')));
    return deserialiseTreeHelper(rootNodeValue,mp);
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

    string serialisedTree = "";
    serialiseTree(root, serialisedTree);
    cout<<"After serialising"<<endl;
    cout<<serialisedTree<<endl;

    node *deserialiseRoot = deserialiseTree(serialisedTree);
    cout<<"After deserialising"<<endl;
    bfs(deserialiseRoot);
}


//           10
//    2    34    56    100
//          1          7 8 9
