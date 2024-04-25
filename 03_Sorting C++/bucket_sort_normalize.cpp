// bucket sort normalized

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void bucketSort_n(float a[],int size){
    vector<vector<float>> v(size,vector<float> ());

    // finding range
    float min_val=INT16_MAX;
    float max_val=INT16_MIN;
    for (int i=0;i<size;i++){
        min_val = min(min_val,a[i]);
        max_val = max(max_val,a[i]);
    }

    float range = (max_val - min_val)/size;

    for (int i=0;i<size;i++){
        int index = (a[i]-min_val)/range;
        // boundary element
        float diff = (a[i]-min_val)/range  - index;
        if (diff == 0 && a[i]!=min_val){
            v[index].push_back(a[i]);
        }
        else{
            v[index].push_back(a[i]);
        }
    }

    for (int i=0;i<size;i++){
        if (!v[i].empty()){
            sort(v[i].begin(),v[i].end());
        }
    }

    int k=0;
    for (int i=0;i<size;i++){
        for (int j=0;j<v[i].size();j++){
            a[k++] = v[i][j];
        }

    }

}

int main(){
    float a[]={4.5,3.1,6.8,7.1,3.3,2.1,3.3};
    int size=sizeof(a)/sizeof(a[0]);
    bucketSort_n(a,size);

    for (int i=0;i<size;i++){
        cout<<a[i]<<" ";
    }
}

