// MAP

#include<iostream>
#include<map>
using namespace std;

int main(){
    map <string,int,greater<string>> directory;             //decreasing order
    // map <string,int> directory;
    directory.insert(make_pair("Z",95695));                 // way 1 (inserting)
    directory["A"] = 1093;                                  // way 2 (inserting)
    directory["B"] = 1093;
    directory["F"] = 1093;
    directory["D"] = 1093;

    for(auto ele : directory){
        string key = ele.first;
        int value = ele.second;
        cout<<key<<"  "<<value<<endl;
    }
    cout<<endl;

    directory["B"] = 999999;                                 // update
    
    // for(auto ele : directory){
    //     string key = ele.first;
    //     int value = ele.second;
    //     cout<<key<<"  "<<value<<endl;
    // }

    map<string,int> ::iterator itr;
    for (itr = directory.begin();itr!=directory.end();itr++){
        cout << "Key: " << (*itr).first << ", Value:" <<(*itr).second << endl ;
    }
}
