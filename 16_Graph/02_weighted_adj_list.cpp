#include<iostream>
#include<vector>
#include<list>
using namespace std;

vector<list<pair<int,int>>> graph;
int v; // no. of vertices
void add_edge(int src,int dest,int wt,bool bi_dir = true){
    graph[src].push_back({dest,wt});
    if (bi_dir){
        graph[dest].push_back({src,wt});
    }
}
void display(){
    for (int i=0;i<graph.size();i++){
        cout<<i<<"->";
        for (auto el:graph[i]){
            cout <<"("<<el.first<<" "<<el.second<<") ,";
        }
        cout<<endl;
    }
}

int main(){
    cin>>v;
    graph.resize(v,list<pair<int,int>> ());
    int e;
    cin>>e;
    while (e--) {
        int s,d,wt;
        cin>>s>>d>>wt;
        add_edge(s, d,wt);           // for undirected
        // add_edge(s, d,wt,false);           // for directed
    }
    display();

}

// input ----------------------------------
// 7 
// 7
// 0 2 2
// 0 1 1
// 1 5 3
// 2 5 2
// 2 3 6
// 3 6 2
// 6 4 6
// output (directed) -----------------------
// 0->(2 2) ,(1 1) ,
// 1->(0 1) ,(5 3) ,
// 2->(0 2) ,(5 2) ,(3 6) ,
// 3->(2 6) ,(6 2) ,
// 4->(6 6) ,
// 5->(1 3) ,(2 2) ,
// 6->(3 2) ,(4 6) ,