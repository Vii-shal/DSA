// find square root of given non negative value x.

#include<iostream>
using namespace std;

int squareRoot(int n){
    int l=1;
    int r=n;
    int ans=-1;
    while (l<=r) {
        int mid = l + ((r-l)/2);
        if (mid*mid <= n){
            ans = mid;
            l=mid+1;
        }
        else {
            r=mid-1;
        }
    }
    return ans;

}

int main(){
    int n=40;
    cout<<squareRoot(n);
}