// evaluate infix .

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

int precedence(char ch){
    if (ch=='^') return 3;
    else if (ch == '*' or ch == '/') return 2;
    else if (ch == '+' or ch == '-') return 1;
    else return -1;
}

int eval(string &str){
    stack<int> nums;
    stack<int> ops;
    for (int i=0;i<str.size();i++){
        if (isdigit(str[i])){
            nums.push(str[i]-'0');
        }
        else if(str[i] == '('){
            ops.push(str[i]);
        }
        else if(str[i] == ')'){
            while (!ops.empty() and ops.top()!= '(') {
                char op = ops.top();
                ops.pop();

                int v1 = nums.top();
                nums.pop();
                int v2 = nums.top();
                nums.pop();
                nums.push(calc(v2,v1,op));
            }
            if (not ops.empty()) ops.pop();
        }
        else{
            while (not ops.empty() and precedence(ops.top()) >= precedence(str[i])){
                char op = ops.top();
                ops.pop();
                int v1 = nums.top();
                nums.pop();
                int v2 = nums.top();
                nums.pop();
                nums.push(calc(v2,v1,op));
            }
            ops.push(str[i]);
        }
    }
    while(!ops.empty()){
            char op = ops.top();
            ops.pop();
            int v1 = nums.top();
            nums.pop();
            int v2 = nums.top();
            nums.pop();
            nums.push(calc(v2,v1,op));
    }
    return nums.top();
}

int main(){
    string str = "1+(2*(3-1))+1";
    int result = eval(str);
    cout <<result<<endl;
    return 0;

}