// multimap implementation 

#include<iostream>
#include<map>
using namespace std;

int main(){
    multimap <string, int > m1;
    m1.insert(make_pair("a", 4)); // insert a pair of value and key in map
    m1.insert(make_pair("d", 2)); // insert a pair of value and key in map
    m1.insert(make_pair("c", 2)); // insert a pair of value and key in map
    m1.insert(make_pair("a", 9)); // insert a pair of value and key in map
    m1.insert(make_pair("c", 12)); // insert a pair of value and key in map
    m1.insert(make_pair("f", 2)); // insert a pair of value and key in map
    // m1["f"] = 55;                 // not allowed in multimap 

    for (auto pair : m1){
        cout << "Key: "<< pair.first << ", Value: " << pair.second << endl;
    }
}
