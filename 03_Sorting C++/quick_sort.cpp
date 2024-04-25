#include<iostream>
using namespace std;

int partition(int a[],int first,int last){

    int pivot = a[last];
    int i=first-1;
    for (int j=first;j<last;j++){
        if (a[j]<pivot){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[last]);
    return i+1;
}
// -----------------------------
//   Randomized pivot               ,time complexity-> n(log(n))
// -----------------------------
// int partition_r(int a[],int first,int last){
//     int random= first +rand()%(last - first);
//     swap(a[random],a[last]) ;
//     return  partition(a,first,last);
// }

void quickSort(int a[],int first,int last ){
    if (first >= last)  return;
    // int pi = partition_r(a,first,last);
    int pi = partition(a,first,last);
    quickSort(a,first,pi-1);
    quickSort(a,pi+1,last);

}

int main(){
    int a[]={18,12,30,16,35,20};
    int n=sizeof(a)/sizeof(a[0]);
    quickSort(a,0,n-1);
    for (int i=0;i<n;i++){
        cout<<a[i]<<"  ";
    }
}