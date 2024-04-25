#include<iostream>
#include<list>
using namespace std;

int main(){
    list <int> l1 = {1,2,3,4,5};
    // list <int>::iterator itr;
    auto itr = l1.begin();                                            // (1)
    auto itr2 = l1.end();                                             // (2)
    // l1.end() iterator pointing to the memory location after 5
    cout<<*itr<<endl;
    cout<<*itr2<<endl;

    auto itr3 = l1.rbegin();                                          // (3)
    auto itr4 = l1.rend();                                            // (4)
    cout<<*itr3<<endl;
    cout<<*itr4<<endl;

    advance(itr,2);                                                   // (5)
    cout<<*itr<<endl;

}