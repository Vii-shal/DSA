// balaced brackets 

#include<iostream>
#include<stack>
using namespace std;

// NORMAL WAY--------------------------------------------------------------------

// int checkBalanced(string &s){
//     int counter = 0;
//     int i=0;
//     while(s[i] != '\0'){
//         if (s[i] == '(' ){
//             counter++;
//         }
//         else{
//             if (counter > 0){
//                 counter--;
//             }
//         }
//         i++;
//     } 
//     return counter;
// }

// USING STACK ----------------------------------------------------------------------------------

bool checkBalanced(string &s){
    stack<char> temp ;
    for (char c : s){
        if (c == '('){
            temp.push(c);
        }
        else if(c == ')'){
            if (temp.empty()){
                return false;
            }
            else{
                temp.pop();
            }
        }
    }
    return temp.empty();
}

int main(){
    // string s = "()()()";
    // cout<<checkBalanced(s);

    string str = "(())";
    cout<<checkBalanced(str);

}
