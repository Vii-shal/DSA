#include<iostream>
#include<set>
using namespace std;

int main(){
    set <int> set1;
    // set <int , greater<int> > set2;       // for decreasing order
    set1.insert(3);
    set1.insert(10);
    set1.insert(7);
    set1.insert(9);
    set1.insert(1);
    set1.insert(13);
    set1.insert(11);
    set1.insert(2);

    cout<<set1.size()<<endl;
    set1.insert(3);
    cout<<set1.size()<<endl;

    // set<int>::iterator itr;
    for (auto itr = set1.begin() ; itr != set1.end() ; itr++){
        cout<<*itr<<"  ";
    }
    cout<<endl;


    // deletion -------------------------------------------------------
    set1.erase(9);                       //number
    for (auto val:set1){
        cout<<val<<"  ";
    }
    cout<<endl;

    auto itr = set1.begin();             // itr
    advance(itr,3);
    set1.erase(itr);
    for (auto val:set1){
        cout<<val<<"  ";
    }
    cout<<endl;

    auto itr1 = set1.begin();
    auto itr2 = set1.begin();
    advance(itr1,2);     
    advance(itr2,4);     
    set1.erase(itr1,itr2);
    for (auto val:set1){
        cout<<val<<"  ";
    }
    cout<<endl;




}
