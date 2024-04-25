#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

string check_isomorphism(vector<string> &st){
    string s=st[0];
    int same_length = s.length();

    for (int i=1;i<st.size();i++){
        int j=0;
        while (j<s.length() && j<st[i].length() && s[j]==st[i][j] ){
            j++;
        }
        same_length = min(same_length,j);
    }
    string ans = s.substr(0,same_length);
    return  ans ;
}

int main(){
    vector<string> str={"ant","anti","angeraje"};
    cout<<check_isomorphism(str);
}