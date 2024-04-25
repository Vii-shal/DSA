// Smallest Number
// the task is to find a smallest number with given number of digits as D and given sum as S.

#include<iostream>
#include<vector>
using namespace std;

void smallestNumber(int d,int s){
    vector<char> v(d,'0');
    if (9*d < s){
        cout<<"-1";
        return;
    }
    s--;
    int i;
    for (i=d-1;i>=0;i--){
        if (s<9) break;
        v[i]='9';
        s-=9;            
    }
    v[0] = '1';
    v[i] = char(s + '0');
    

    for (int i=0;i<v.size();i++){
        cout << v[i];
    }

}

int main(){
    cout<<"enter d and s";
    int d,s;
    cin>>d>>s;
    smallestNumber(d,s);

}