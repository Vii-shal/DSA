// sudoku  ************

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool canPlace(vector<vector<char>>& board , int row ,int col,char num){
        for (int i=0;i<9;i++){
            if (board[row][i]==num) return false;
        }
        for (int i=0;i<9;i++){
            if (board[i][col]==num) return false;
        }
        int r =(row/3)*3;
        int c =(col/3)*3;
        for (int i=r;i<r+3;i++){
            for (int j=c;j<c+3;j++){
                if (board[i][j] == num) return false;
            }
        }
        return true;
    }

    bool sudoku(vector<vector<char>>& board , int row ,int col){
        if (col == 9)  return sudoku(board,row+1,0);
        if (row == 9)  return true;
        
        if (board[row][col] == '.'){
            for (int num=1;num<=9;num++){
                if (canPlace(board,row,col,'0' + num)){
                    board[row][col] = '0'+num;
                    bool res = sudoku(board,row,col+1);
                    if(res) return true;
                    board[row][col] = '.';
                }
            }
            return false;
        }
        else{
            return sudoku(board,row,col+1);
        }

    }

    void solveSudoku(vector<vector<char>>& board) {
        sudoku(board,0,0);
    }
};

int main(){
    int n=9;
    // vector<vector<int>> v(9,vector<int> (9,'.')); 
    vector<vector<char>> v(n,vector<char> (n,'.'));
    Solution s;
    // s.solveSudoku(v);
    cout<<s.sudoku(v,0,0);
        cout<<endl;
    for (int i=0;i<v.size();i++){
        for (int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}