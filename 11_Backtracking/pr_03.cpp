// N queens .

#include<iostream>
#include<vector>
using namespace std;

bool canPlaceQueen(int row ,int col,vector<vector<char>> grid){
    // is someone attacking from vertical up
    for (int i=row-1;i>=0;i--){
        if (grid[i][col] == 'Q'){
            return false;
        }
    }
    for (int i=row-1 , j=col-1 ;i>=0 && j>=0 ;i--,j--){            // back-up diagonal
        if (grid[i][j]=='Q'){
            return false;
        }
    }
    for (int i=row-1 , j=col+1 ;i>=0 && j<grid.size() ;i--,j++){   // front-up diagonal
        if (grid[i][j]=='Q'){
            return false;
        }
    }
    return true;
}

void nQueen(int currRow , int n,vector<vector<char>> &grid){
    if (currRow == n) {
        for (int i=0;i<n;i++){                        // printing grid
            for (int j=0;j<n;j++){
                cout<< grid[i][j] <<" ";
            }
            cout<<endl;
        }
        cout<<"------------------"<<endl;
    }

    for (int col = 0;col<n;col++){
        // we will go to all the cols
        // lets check if we can place a queen at currRow and col
        if (canPlaceQueen(currRow,col,grid)){
            grid[currRow][col] = 'Q';
            nQueen(currRow+1,n,grid);
            grid[currRow][col] = '.';
        }
    }


}

int main(){
    int n=5;
    vector<vector<char>> grid(n,vector<char> (n,'.'));
    nQueen(0, n, grid);
    return 0;
}
