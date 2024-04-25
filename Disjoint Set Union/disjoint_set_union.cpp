#include<iostream>
#include<vector>
using namespace std;

int find(vector<int> &parent,int x){
    // time complexity : (log*n);
    // this method returns which group/cluster x belongs to
    return parent[x] = (parent[x]==x)?x:find(parent,parent[x]);
}

void Union(vector<int> &parent , vector<int> &rank , int a, int b){
    // time complexity : (log*n);
    a = find(parent,a);
    b = find(parent,b);

    if (rank[a] >= rank[b]){
        rank[a]++;
        parent[b] = a;
    }
    else{
        rank[b]++;
        parent[a] = b;
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    // n->elements , m->no. of queries
    vector<int> parent(n+1);
    vector<int> rank(n+1,0);
    for(int i=1;i<=n;i++){
        parent[i] = i;
    }

    while(m--){
        string str;
        cin>>str;
        if (str == "union"){
            int x,y;
            cin>>x>>y;
            Union(parent,rank,x,y);
        }
        else{
            int x;
            cin>>x;
            cout<<find(parent,x)<<endl;
        }
    }
}




// example 1------------
// 5
// 4
// union
// 2 3
// union
// 3 4
// union
// 1 3
// find
// 2
// 2
// find
// 3
// 2
// find  
// 4
// 2