// check whether a given bracket sequence is balanced or not ?

#include<iostream>
#include<stack>
using namespace std;

bool checkBalance(string &s){                                        // time complexity = O(n)
    stack<char> st;
    for (int i=0;i<s.size();i++){
        int ch = s[i];
        if (ch=='(' || ch=='{' || ch=='[' ){
            st.push((char)ch);
        }
        else {
            if (ch==')' && !st.empty() && st.top()=='('){
                st.pop();
            }
            else if (ch=='}' && !st.empty() && st.top()=='{'){
                st.pop();
            }
            else if (ch==']' && !st.empty() && st.top()=='['){
                st.pop();
            }
            else{
                return false;
            }
        }
    }
    return st.empty();
}

int main(){
    string s = "{[()]}";
    if (checkBalance(s)){
        cout<<"Balanced";
    }
    else {
        cout << "Not Balanced" ;
    }
}
