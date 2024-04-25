#include<iostream>
#include<list>
using namespace std;

int main(){
    list<int> l1 = {1,2,3,4,5};
    auto itr = l1.begin();
    advance(itr,2);

    // l1.insert(itr,8);                          // (1)
    // for (auto show :l1 ){
    //     cout<<show<<" ";
    // }
    // cout<<endl;

    // l1.insert(itr,2,8);                       // (2)
    // for (auto show :l1 ){
    //     cout<<show<<" ";
    // }
    // cout<<endl;

    auto l = l1.begin();                         // (3)
    auto r = l1.begin();
    advance(r,2);
    l1.insert(itr,l,r);
    for (auto show :l1 ){
        cout<<show<<" ";
    }
    cout<<endl;


}
