// find kth largest element 

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int KthLargestElements(vector<int> a,int n,int k){
    priority_queue < int , vector<int>, greater<int>> pq;  //minheap
    for (int i=0;i<n;i++){
        pq.push(a[i]);
        if (pq.size()>k){
            pq.pop();   // remove the smallest element out of k+1 elements
        }
    }
    return pq.top();
}

int main() {
    int n,k;
    cout<<"enter n and k"<<endl;
    cin>>n>>k;
    vector<int> a(n);
    for (int i=0;i<n;i++){
        cin >>a[i];
    }
    cout<<KthLargestElements(a,n,k)<<endl;
}
