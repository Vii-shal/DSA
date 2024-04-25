// search a target value in a 2d integer matrix of dimensions nxm and return 1 if found else return 0. this matrix have following properties .
// (1)  integers in each row are sorted from left to right .
// (2)  the first integer of each row is greater then last integer of previous row .

#include<iostream>
#include<vector>
using namespace std;

int find(vector<vector<int>> &v,int target){
    int n=v.size() ,m=v[0].size();
    int l=0;
    int r=n*m -1;
    while (l<=r){
        int mid = l+((r-l)/2);
        int x=mid/m;
        int y=mid%m;
        if (v[x][y] == target){
            return 1;
        }
        else if(v[x][y]>target){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return -1;
}


int main(){
    vector <vector<int>> v = {{1,3,5,6},{8,9,11,15},{16,17,19,20}};
    int target;cin>>target;
    cout<<find(v,target);

    
}