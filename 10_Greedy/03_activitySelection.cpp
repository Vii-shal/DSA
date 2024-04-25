// max no. of activities that can be performed 

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct activity{
    int start;
    int end;
};

static bool cmp(activity a,activity b){
    return a.end < b.end;
}

int maxActivitiesPerformed(vector<activity> arr){
    sort(arr.begin(),arr.end(),cmp);
    activity last = arr[0];
    int count=1;
    for (int i=1;i<arr.size();i++){
        if (last.end < arr[i].start){
            count++;
            last = arr[i];
        }
    }
    return count;
}

int main(){
    // start = {1,3,2,5}
    // end = {2,4,3,6}
    vector<activity> arr={{1,2},
                          {3,4},
                          {2,3},
                          {5,6}};

    cout<< maxActivitiesPerformed(arr);

}