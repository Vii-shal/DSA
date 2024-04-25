#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

bool check_anagram(string s,string t){
    vector <int> freq(26);

    if (s.length() != t.length()){
        return false;
    }
    for (int i=0;i<s.length();i++){
        freq[s[i] - 'a']++;
        freq[t[i] - 'a']--;
    }
    for (int i=0;i<26;i++){
        if (freq[i] != 0){
            return false;
        }
    }
    return true;
}

int main(){
    string s="anagram";
    string t="gramana";
    if (check_anagram(s,t)){
        cout<<"s and t is Anagrams"<<endl;
        }
    else{
        cout<< "not anagrams" << endl;
    }
}