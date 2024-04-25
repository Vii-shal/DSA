// Given n integers (can be duplicates) , print the second smallest integer.
// if i tdoes not exist , print -1.

#include<iostream>
#include<vector>
#include<set>
using namespace std;

int secondSmallest(vector<int> &v){
    set<int> s;
    for(auto x: v ){
        s.insert(x);
    }
    if (s.size() < 2){
        return -1;
    }

    auto itr = s.begin();
    return *(++itr);
}

int main(){
    vector<int> v = {1,2,2,-4};
    // vector<int> v = {1,2,3,1,1};
    // vector<int> v = {1,1,1};
    cout<<secondSmallest(v)<<endl;
}
