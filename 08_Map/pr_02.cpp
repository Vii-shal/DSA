// can we make strings equal

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

bool canMakeEqual(vector<string> &v){
    unordered_map <char,int> m;
    for (auto str : v){
        for (char c : str){
            m[c]++;
        }
    }
    for (auto pair:m){
        if (pair.second % (v.size()) != 0){
            return false;
        }
    }
    return true;

}

int main(){
    vector<string> v = {"collegeee","coll","collegge"};
    cout<<(canMakeEqual(v)?"yes":"no")<<endl;

}

