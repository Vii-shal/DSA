#include<iostream>
#include<queue>
using namespace std;

vector<pair<int,int>> kClosestPoints(vector<pair<int,int>>pts,int n,int k){
    priority_queue<pair<int,pair<int,int>>> pq; // max heap
    for (auto &pt : pts){
        int distance = pt.first + pt.second;
        pq.push(make_pair(distance,pt));
        if (pq.size() > k){
            pq.pop();          //  remove largest distance pt in k+1 pts
        }
    }
    vector<pair<int,int>> res(k);
    while (!pq.empty()){
        res[pq.size()-1] = pq.top().second;
        pq.pop();
    }
    return res;
}

int main(){
    cout<<"enter n amd k";
    int n,k;
    cin>>n>>k;
    vector<pair<int,int>> pts(n);
    for (auto &pt : pts){
        cin>>pt.first>>pt.second;
    }
    vector<pair<int,int>> ans_pts = kClosestPoints(pts,n,k);
    for (auto &pt : ans_pts){
        cout<<pt.first<<"  "<<pt.second<<'\n';
    }

}