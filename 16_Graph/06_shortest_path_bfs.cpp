// shortest path 

#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<unordered_set>
using namespace std;

vector<list<int>> graph;
unordered_set<int> visited;
// vector<vector<int>>result;
int v; // no. of vertices
void add_edge(int src,int dest,bool bi_dir = true){
    graph[src].push_back(dest);
    if (bi_dir){
        graph[dest].push_back(src);
    }
}

void bfs(int src,vector<int> &dist){
    queue<int> qu;
    visited.clear();
    dist.resize(v,INT16_MAX);
    dist[src] = 0;
    visited.insert(src);
    qu.push(src);
    while (not qu.empty()){
        int curr = qu.front();
        cout<<curr<<" ";
        qu.pop();
        for (auto neighbour:graph[curr]){
            if (not visited.count(neighbour)){
                qu.push(neighbour);
                visited.insert(neighbour);
                dist[neighbour] = dist[curr]+1;
            }
        }
    }
    cout<<endl;
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
        add_edge(s, d);           // for undirected
        // add_edge(s, d,false);           // for directed
    }
    int x;
    cin>>x;
    vector<int> dist;
    bfs(x,dist);
    for (int i=0;i<dist.size();i++){
        cout<<dist[i]<<" ";
    }

    return 0;
}



// input -----------------------------------------------------
// 7
// 8
// 0 1
// 0 4
// 1 3
// 4 3
// 1 5
// 5 6
// 6 2
// 5 2
// 0     // src 
// output ----------------------------------------------------
// 0 1 3 2 1 2 3 