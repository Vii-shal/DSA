#include<iostream>
#include<cmath>
using namespace std;

void survive(int S,int M,int N){
    int maxFoodBuy = (S-S/7)*N;
    int maxFoodReq = S*M;
    if (maxFoodBuy < maxFoodReq){
        cout<<"No Surivive\n";
    }
    else{
        cout<<"Survive\n";
        float ans = float(S)*float(M)/float(N);
        cout<<"no. of days we need to buy : "<<ceil(ans);
    }
}

int main(){
    int S = 10; // no. of days to survive
    int M = 2;  // unit of food required each day to survive
    int N = 16; // max unit of food you can buy each day
    survive(S,M,N);

}