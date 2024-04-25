// find length of the longest sub array equal to zero .

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int longestSubArray(vector<int> &v){

    unordered_map <int,int> m;
    int prefix_sum = 0;
    int maxlen = 0;

    for (int i=0;i<v.size();i++){
        prefix_sum += v[i];
        if (prefix_sum == 0){
            maxlen++;
        }

        if (m.find(prefix_sum) != m.end()){
            maxlen = max(maxlen , i - m[prefix_sum]);
        }
        else{
            m[prefix_sum] = i;
        }
    }
    return maxlen;
}

int main(){
    // vector<int> v = {15,-2,2,-8,1,7,10,23};
    vector<int> v = {1,2,3};
    cout<<longestSubArray(v)<<endl;;

}
