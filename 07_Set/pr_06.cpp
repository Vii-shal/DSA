#include<iostream>
#include<unordered_set>
using namespace std;

int main(){
    int n = 2;             // number of questions
    int p = 1;             // marks for correct ans
    int q = -1;            // marks for incorrect ans
    unordered_set<int> un;

    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            int correct = i;
            int incorrect = j;
            int unattended = n-i-j;

            if (unattended >= 0){
                int score = correct*p + incorrect*q;
                un.insert(score);
            }
            else{
                break;
            }
        }
    }

    cout<<"total posabilities : "<<un.size()<<endl;
    for (auto x : un){
        cout <<x<<" ";
    }
}
