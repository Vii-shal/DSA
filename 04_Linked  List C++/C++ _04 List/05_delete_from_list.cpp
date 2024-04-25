#include<iostream>
#include<list>
using namespace std;

int main(){
    list<int> l1 = {1,2,3,4,5,6,7,8,9};
    auto itr = l1.begin();
    advance(itr,2);

    // l1.erase(itr);                                       // (1)
    // for (auto show:l1){
    //     cout<<show<<" ";
    // }
    // cout<<endl;

    auto str_itr = l1.begin();                              // (2)
    advance(str_itr,5); // pointing to 6th element
    auto last_itr = l1.begin();
    advance(last_itr,7); // pointing to 8th element
    l1.erase(str_itr,last_itr);
    for (auto show:l1){
        cout<<show<<" ";
    }
    cout<<endl;

}