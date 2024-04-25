// unordered_map implementation 

#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    unordered_map <int,string> record; 
    record.insert(make_pair(3,"ria"));
    record[1] = "riya";
    record[9] = "bali";
    record[9] = "umesg";

    for (auto pair:record){
        cout<<pair.first<<" "<<pair.second<<endl;
    }
}
