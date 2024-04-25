// Given two vectors that represent a sequence of keys . Imagine we make a BST for each array . 
// We need to tell wether two BSTs will be identical or not without actually constructing the trees .

#include<iostream>
#include<vector>
using namespace std;

bool checkIdenticalBSTHelper(vector<int> &v1,vector<int> &v2,int a1,int a2,int minVal,int maxVal){
    // find the first element in v1 within range
    int i;
    for (i=a1;i<v1.size();i++){
        if (v1[i]>minVal && v1[i]<maxVal)  break;
    }

    // find the first element in v2 within range
    int j;
    for (j=a2;j<v2.size();j++){
        if (v2[j]>minVal && v2[j]<maxVal)  break;
    }

    // if no element is found within range (leaf nodes)
    if (i==v1.size() && j==v2.size()) return true;

    // if only one vector does not have elements within range
    if ((i==v1.size() && j!=v2.size()) && (i!=v1.size() && j==v2.size())){
        return false;
    }

    // checking if both elements are equal or not
    if (v1[i]!=v2[j]) return false;

    // recursively check for left and right subtree
    return checkIdenticalBSTHelper(v1,v2,a1+1,a2+1,minVal,v1[i]) && 
          checkIdenticalBSTHelper(v1,v2,a1+1,a2+1,v1[i],maxVal);
}

bool checkIdenticalBST(vector<int>& v1,vector<int> &v2){
    return checkIdenticalBSTHelper(v1,v2,0,0,INT16_MIN,INT16_MAX);
}

int main(){
    cout<<"Enter input - "<<endl;
    int n;cin>>n;
    vector<int> v1(n),v2(n);

    for (int i=0;i<n;i++){
        cin>>v1[i];
    }
    for (int i=0;i<n;i++){
        cin>>v2[i];
    }

    if (checkIdenticalBST(v1,v2)){
        cout<<"BTS are identical. "<<endl;
    }
    else{
        cout<<"BTS are NOT identical. "<<endl;
    }

}



