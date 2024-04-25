// unordered set 

#include<iostream>
#include<unordered_set>
using namespace std;

int main(){
    unordered_set<int> s1;
    s1.insert(3);
    s1.insert(4);
    s1.insert(5);
    s1.insert(6);

    for(auto val:s1){
        cout<<val<<" ";
    }
}
