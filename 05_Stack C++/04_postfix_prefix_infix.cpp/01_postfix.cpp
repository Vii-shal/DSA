// evaluation of postfix .

#include<iostream>
#include<stack>
#include<math.h>
using namespace std;

int calc(int v1,int v2,char op){
    if (op == '+'){
        return v1+v2;
    }
    if (op == '-'){
        return v1-v2;
    }
    if (op == '*'){
        return v1*v2;
    }
    if (op == '/'){
        return v1/v2;
    }
    if (op == '^'){
        return pow(v1,v2);
    }
    return 0;
}

int eval(string &s){
    stack<int> st;
    for (int i=0;i<s.size();i++){
        if (isdigit(s[i])){
            st.push(s[i] - '0');
        }
        else{
            int v1 = st.top();
            st.pop();
            int v2 = st.top();
            st.pop();
            int res = calc(v2,v1,s[i]);
            st.push(res);
        }
    }
    return st.top();
}

int main(){
    string s = "231*+9-";
    cout<<eval(s)<<endl;

}
