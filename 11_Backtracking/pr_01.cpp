// Find all permutation of a string 
// O(n!)  n-> size of string.

#include<iostream>
using namespace std;

void permutation(string &str , int i){
    if (i == str.size()){
        cout<<str<<"\n";
        return;
    }
    for (int j=i;j<str.size();j++){
        swap(str[i],str[j]);
        permutation(str,i+1);
        swap(str[i],str[j]);
    }
}

int main(){
    string str = "abc";
    permutation(str,0);

}
