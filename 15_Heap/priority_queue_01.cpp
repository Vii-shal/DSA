#include<iostream>
#include<queue>
using namespace std;

int main(){
    priority_queue<int> pq1;    // max heap
    pq1.push(5);
    pq1.push(1);
    pq1.push(8);
    pq1.push(7);

    while (!pq1.empty()){
        cout << " " << pq1.top();
        pq1.pop();
    }
    cout<<endl;

    priority_queue<int,vector<int>,greater<int>> pq2;  //min heap
    pq1.push(5);
    pq1.push(1);
    pq1.push(8);
    pq1.push(7);
    while(!pq2.empty()){
        cout<<" "<<pq2.top();
        pq2.pop();
    }

}