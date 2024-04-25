// Check anagram 

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

bool checkAnagram(string &str1,string &str2){
    if (str1.size() != str2.size()){
        return false;
    }

    unordered_map<char,int> m;
    for (auto c1:str1){
        m[c1]++;
    }
    for (auto c2 : str2) {
        if (m.find(c2) == m.end()){
            return false;
        }
        else{
            m[c2]--;
        }
    }

    for (auto ele : m){
        if (ele.second != 0){
            return false;
        }
    }
    return true;

}

int main(){
    string s1,s2;
    cin>>s1>>s2;
    cout<<checkAnagram(s1,s2)<<endl;

}