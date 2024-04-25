// count number of brackets to be removed for balanced brackets .

#include<iostream>
#include<stack>
using namespace std;

int removeBrackets(string &s){                                        // time complexity = O(n)
    stack<char> st;
    int count = 0;
    for (int i=0;i<s.size();i++) {
        if (s[i]=='('){
            st.push(s[i]);
        }
        else{
            if (!st.empty()){
                st.pop();
            }
            else{
                count++;
            }
        }
    }
    while(!st.empty()){
        count++;
        st.pop();
    }
    return count;  
}

int main(){
    string s = "())))";
    cout<<removeBrackets(s);
}
