//   multiset 

#include<iostream>
#include<set>
using namespace std;

int main(){
    multiset <int> ms;
    ms.insert(1);
    ms.insert(2);
    ms.insert(4);
    ms.insert(8);
    ms.insert(10);
    for(auto val:ms){
        cout<<val<<" ";
    }
    cout<<endl;
    auto itr = ms.lower_bound(3);
    cout<< *itr<<endl;
}

