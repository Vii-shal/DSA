// sort  a string

#include<iostream>
#include<vector>
using namespace std;

string count(string st){
    vector<int> freq(26);

    // storing freq of every character in string 
    for (int i=0;i<st.length();i++){
        int index = st[i]-'a';
        freq[index]++;
    }

    // create our sorted array
    int j=0;
    for (int i=0;i<26;i++){
        while(freq[i]--){
            st[j] = i+'a';
            j++;
        }
    }
    return st;
}

int main(){
    string st = "adbccada";
       cout<<count(st)<<endl;
}