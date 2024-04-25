// given a graph check whether there is a path from src to dest via the neighbour.

#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
using namespace std;

vector<list<int>> graph;
unordered_set<int> visited;
int v; // no. of vertices
void add_edge(int src,int dest,bool bi_dir = true){
    graph[src].push_back(dest);
    if (bi_dir){
        graph[dest].push_back(src);
    }
}

bool dfs(int curr,int end){
    if (curr == end) return true;
    visited.insert(curr);  // marked visited
    for (auto neighbour:graph[curr]){
        if (not visited.count(neighbour)){
            bool result = dfs(neighbour,end);
            if (result) return true;
        }
    }
    return false;
}

bool anyPath(int src,int dest){
    return dfs(src,dest);
}

int main(){
    cin>>v;
    graph.resize(v,list<int> ());
    int e;
    cin>>e;
    visited.clear();
    while (e--) {
        int s,d;
        cin>>s>>d;
        // add_edge(s, d);           // for undirected
        add_edge(s, d,false);           // for directed
    }
    int x,y;
    cin>>x>>y;
    cout<<anyPath(x,y)<<endl;
    return 0;
}



// input --------------------------------------
// 7 
// 8
// 0 1
// 0 4
// 4 3
// 1 3
// 1 5
// 5 6
// 6 2
// 5 2
// 0 6   // finding path b/w these two vertices
// output -------------------------------------
// 1     // true , path exists