#include<iostream>
#include<list>
using namespace std;

int main(){
    list <int> l1 = {1,2,3,4,5};
    auto itr = l1.begin();

    // Using range-based loop
    for (auto num : l1){
        cout<<num<<"  ";
    }
    cout<<endl;

    // Using iterators
    for (auto itr = l1.begin() ; itr!=l1.end() ; itr++){
        cout<<*itr<<"  ";
    }
    cout<<endl;

    // Reverse traversal
    for (auto itr = l1.rbegin() ; itr!=l1.rend() ;itr++ ){
        cout<<*itr<<"  ";
    }
}
 