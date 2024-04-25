// max sliding problem 

#include<iostream>
#include<vector>
#include<deque>
using namespace std;

   vector<int> maxSlidingWindow(vector<int>& v, int k) {
        deque <int> d;
        vector<int>res;
        for (int i=0;i<k;i++){
            while(!d.empty() && v[d.back()]<v[i]){
                d.pop_back();
            }
            d.push_back(i);
        }
        res.push_back(v[d.front()]);

        for (int i=k;i<v.size();i++){
            if (d.front() == (i-k)){
                d.pop_front();
            }
            while(!d.empty() && v[d.back()]<v[i]){
                d.pop_back();
            }
            d.push_back(i);
            res.push_back(v[d.front()]);
        }    
    return res;
    } 

int main(){
    vector<int> vec = {1,3,-1,-3,5,3,6,7};
    vector<int> v = maxSlidingWindow(vec,3);
    for (auto x:v){
        cout<<x<<" ";
    }


}
