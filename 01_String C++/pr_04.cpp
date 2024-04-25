#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

string check_isomorphic(vector <string> &v){
    sort(v.begin(),v.end());

    int n=v.size();
    string s1=v[0];
    string s2=v[n-1];
    int i=0,j=0;
    string ans = "";

    while(i<s1.length()  && j<s2.length()){
        if (s1[i]==s2[j]){
            ans += s1[i];
            i++,j++;
        }
        else{
            break;
        }
    }
    return ans;
}

int main(){
    vector <string> str = {"fl ower","flight","flask"};
    cout<<check_isomorphic(str);

}