#include<iostream>
#include<vector>
using namespace std;

void sort(vector <int> &v){
    int n=v.size();
    // finding max
    int max=INT16_MIN;
    for (int i=0;i<n;i++){
        if (max<v[i]){
            max=v[i];
        }
    }
    cout<<max<<endl;

    // creating freq array
    vector <int> freq(max+1,0);
    for (int j = 0 ;j<n;j++){
        freq[v[j]]++;
    }

    // prefix sum or cumulative array
    for (int i=1;i<=max;i++){
        freq[i] += freq[i-1];
    }

    // ans array  or sorted array
    vector <int> ans(n);
    for (int i=n-1;i>=0;i--){
        ans[--freq[v[i]]] = v[i];
    }

    // copy back the answer
    for (int i=0;i<n;i++){
        v[i]=ans[i];    
    }
}

int main(){
    vector <int> v = {4,2,8,3,11,70,1,33};
    sort(v);
    for (int i=0;i<v.size();i++){
        cout<<v[i]<<"  ";    
    }
}