// unordered multimap implementation

#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    unordered_map<string,int> fruitcount;

    fruitcount.insert(make_pair("apple",6));
    fruitcount.insert(make_pair("banana",9));
    fruitcount.insert(make_pair("appl",3));
    for (auto pair:fruitcount){
        cout<<pair.first<<" "<<pair.second<<endl;
    }
}
