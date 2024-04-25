#include<iostream>
#include<vector>
#include<list>
using namespace std;

vector<list<int>> graph;
int v; // no. of vertices
void add_edge(int src,int dest,bool bi_dir = true){
    graph[src].push_back(dest);
    if (bi_dir){
        graph[dest].push_back(src);
    }
}
void display(){
    for (int i=0;i<graph.size();i++){
        cout<<i<<"->";
        for (auto el:graph[i]){
            cout <<el<<",";
        }
        cout<<endl;
    }
}

int main(){
    cin>>v;
    graph.resize(v,list<int> ());
    int e;
    cin>>e;
    while (e--) {
        int s,d;
        cin>>s>>d;
        // add_edge(s, d);           // for undirected
        add_edge(s, d,false);           // for directed
    }
    display();

}

// input------------------------------
// 7
// 7
// 0 2
// 0 1
// 1 5
// 5 2
// 3 2
// 6 3
// 6 4
// output (directed) -----------------
// 0->2,1,
// 1->5,
// 2->
// 3->2,
// 4->
// 5->2,
// 6->3,4,