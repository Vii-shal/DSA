// Give an array names of the fruits; you are supposed to sort it in lexicographical order using selection sort 
// input ->  ["papaya","lime","watermelon","apple","mango","kiwi"]
// output -> ["apple","kiwi","lime","mango","papaya","watermelon"]


#include<iostream>
#include<cstring>
using namespace std;

void sort(char fruit[][60]  , int n){
    for (int i =0 ;i <n-1;i++) {
        int min_ind = i;
        for (int j=i;j<n;j++){
            if (strcmp(fruit[min_ind],fruit[j]) > 0){
                min_ind=j;
            }
        }
        if (i!=min_ind){
        swap(fruit[min_ind],fruit[i]);
        }
    }

}


int main(){
    char  fruit[][60]={"papaya","lime","watermelon","apple","mango","kiwi"};
    int n=sizeof(fruit)/sizeof(fruit[0]);
    sort(fruit,n);
    for (auto x:fruit) cout<<x<<" ";
}