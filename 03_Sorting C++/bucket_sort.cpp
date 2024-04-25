#include<iostream>
#include<algorithm>
#include<Vector>
using namespace std;

void bucketSort(float a[],int n){
    // step 1
    vector<vector<float>> bucket(n , vector <float> ());

    // step 2 : inserting elements to bucket 
    for (int i=0;i<n;i++){
        int index = a[i]*n;
        bucket[index].push_back(a[i]);
    }

    // step 3 : sorting individual buckets 
    for (int i=0;i<n;i++){
        if (!bucket[i].empty()){
            sort(bucket[i].begin() , bucket[i].end());
        }
    }

    // step 4 : combining elements from buckets 
    int k=0;
    for (int i=0;i<n;i++){
        for (int j=0;j<bucket[i].size();j++){
            a[k++]= bucket[i][j];
        }
    }
}

int main(){
    float a[] = {0.13,0.45,0.12,0.89,0.65,0.63,0.85,0.39};
    int size = sizeof(a)/sizeof(a[0]);
    bucketSort(a,size);
    
    for (int i=0;i<size;i++){
        cout<<a[i]<<" ";
    }
}