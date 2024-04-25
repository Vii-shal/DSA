// Check if string have all english alphabets. 

#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

bool checkAllAlphabets(string s){
    if (s.length()<26){
        return false;
    }
    transform(s.begin(),s.end(),s.begin(),::tolower);
    set<int> alphabets;
    for(auto val:s){
        alphabets.insert(val);
    }
    return alphabets.size() == 26;
}

int main() {
    string input;
    cin>>input;

    cout<<checkAllAlphabets(input);
}