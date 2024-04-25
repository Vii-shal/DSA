#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string new_str(string s){
    string result="";

    for (int i=0;i<s.length();i++){
        if (s[i] != ']'){
            result.push_back(s[i]);
        }
        else{

            // extract str from result 
            string str="";
            while(!result.empty()  && result.back() != '['){
                str.push_back(result.back());
                result.pop_back();
            }
            
            // reverse str    
            reverse(str.begin(),str.end());

            // remove last char from str which is [
            result.pop_back();

            // getting num string
            string num="";
            while (!result.empty()  && result.back()>='0'  && result.back()<='9'){
                num.push_back(result.back());
                result.pop_back();
            }

            // reverse num string
            reverse(num.begin(),num.end());

            // convert num from string to integer 
            int n = stoi(num);

            while(n){
                result += str;
                n--;
            }
        }
    }
    return result;
}


int main(){
    // string s="3[b2[ca]]";
    string st;
    cin>>st;
    cout<<new_str(st)<<endl;;
    
}