//   unordered_multiset 

#include<iostream>
#include<unordered_set>
using namespace std;

int main(){
    unordered_multiset <int> ms;
    ms.insert(1);
    ms.insert(2);
    ms.insert(4);
    ms.insert(8);
    ms.insert(10);
    for(auto val:ms){
        cout<<val<<" ";
    }
    cout<<endl;
}

