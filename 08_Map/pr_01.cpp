// sum of repeated elements 

#include<iostream>
#include<vector>
#include<map>
using namespace std;

int repeatedEleSum(vector<int> &v){
    map <int, int> m1; 
    for (int i=0;i<v.size();i++){
        m1[v[i]]++;    
    }
    int sum =0;
    for (auto pair:m1) {
        if(pair.second >1){
            sum += pair.first;
        }
    }
    return sum;

}

int main(){
    vector<int> v ={1,1,2,4,2,1,3,3,3};
    cout<<repeatedEleSum(v);
}