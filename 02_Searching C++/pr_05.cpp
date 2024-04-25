// given a rotataed sorted array of integers which contain distinct elememts ,return index of target if it is in the array 

#include<iostream>
#include<vector>
using namespace std;

void binary_s(vector<int> &a,int target,int l,int r){

    while (l<=r) {
        int mid = (l+r)/2;
        // int mid = l + ((r-l)/2)                                  modified mid to tackle overflow
        if (a[mid]==target){
            cout<<"found at index "<<mid<<endl;
            break;
        }
        else if(a[mid]<target){
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
}

int lowest(vector <int> &v){
    if (v.size()==1) return 0;
    int a=0;
    int b=v.size()-1;
    if (v[a]<v[b]){
        return 0;
    }
    while (a<=b){
       int mid = a + ((b-a)/2);
       if (v[mid] > v[mid+1]) return mid+1;
       if (v[mid] < v[mid-1]) return mid;
       if (v[mid]>v[a]){
        a=mid+1;
       }
       else{
        b=mid-1;
       }
    }
    return -1;
}

int main(){
    vector<int> v={6,7,9,2,3,5};
    int target = 2;                                     // target element
    int xyz=lowest(v);                                 // getting smallest ele index
    if (v[xyz]==target){
        cout<<"found  "<<xyz<<endl;
    }
    else {
    binary_s(v,target,0,xyz-1);                        // searching in left part
    binary_s(v,target,xyz+1,v.size());                 // searching in right part

    }
}
