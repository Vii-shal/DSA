// Rat in a maze 
// number of ways in which a rat can move from start point to destination pint .


#include<iostream>
#include<vector>
using namespace std;

bool canWeGo(int a,int b, vector<vector<int>> &grid){
    return (a<grid.size() and b<grid.size() and a>= 0 and b>= 0) and grid[a][b]==1;
}

int f(int i,int j, vector<vector<int>> &grid ){
    int n = grid.size();
    if (i == n-1 and j == n-1)  return 1;
    // if (i == n-1 and j == n-1) {                        // show pattern from where rat crosses
    //     for (int i=0;i<grid.size();i++){
    //         for (int j=0;j<grid.size();j++){
    //             cout<<grid[i][j]<<" ";
    //         }
    //         cout<<endl;
    //     }
    //     cout<<endl;
    // }


    int ans=0;
    grid[i][j] = 2;
    if (canWeGo(i,j+1,grid)){     // right
        ans += f(i,j+1,grid);
    }
    if (canWeGo(i+1,j,grid)){     // down
        ans += f(i+1,j,grid);
    }
    if (canWeGo(i,j-1,grid)){     // left
        ans += f(i,j-1,grid);
    }
    if (canWeGo(i-1,j,grid)){     // up
        ans += f(i-1,j,grid);
    }
    grid[i][j] = 1;
    return ans;

}

int main(){
    // vector<vector<int>> v = {{1,1,1,1},
    //                          {0,1,0,1},         
    //                          {0,1,1,1},
    //                          {1,1,1,1}};               // ans = 7

    vector<vector<int>> v = {{1,1,1,0},
                             {0,1,1,0},         
                             {0,0,1,0},
                             {0,0,1,1}};

    int ans = f(0,0,v);
    cout<<ans<<endl;
}