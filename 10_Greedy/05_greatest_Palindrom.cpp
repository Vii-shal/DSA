// // using integers 

// #include<iostream>
// #include<map>
// #include<vector>
// using namespace std;

// int digits(int num,map<int,int,greater<int>> &mp){     // getting no. of digits // map <digit,freq> -> dec map
//     int count=0;
//     while(num>0){
//         count++;
//         int d = num%10;
//         mp[d]++;
//         num/=10;
//     }
//     return count;
// }

// void palindrom(int num){
//     map<int,int,greater<int>> mp;
//     int dig = digits(num,mp);
//     int l=0 , r=dig-1;
//     int mid = (l+r)/2;
//     int numOfOddDigit = 0;
//     vector<int> res(dig);

//         for (auto m:mp){

//             while(m.second > 0 && m.second / 2 >0){  // for even freq digits
//                 res[l] = res[r] = m.first;
//                 m.second -= 2;
//                 l++;
//                 r--;
//                 dig-=2;
//             }
            
//             if (m.second % 2!=0){            // for odd freq digits
//                 numOfOddDigit++;
//                 res[mid] = (m.first);
//                 if (numOfOddDigit > 1){
//                     cout<<"palendrom cant be form"<<endl;
//                     return;
//                 }
//             }
//         }

//     for (auto ans:res){
//         cout<<ans<<" ";
//     }
// }


// int main(){
//     int num = 42424;
//     palindrom(num);
// }

// //**************************************************************************************************
// // using string

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

bool isPossible(unordered_map<int,int> &mp){
    int count = 0;
    for (int i=0;i<=9;i++){
        if (mp.count(i)){
            if (mp[i] % 2 != 0) count++;
            if (count>1) return false;
        }
    }
    return true;
}

string max_palindrome(string num){
    int l=num.size();
    unordered_map<int,int> mp;
    for (int i=0;i<l;i++) {
        mp[num[i] - '0']++;
    }
    if (!isPossible(mp)){
        return "NP";
    }
    vector<char> v(l);
    int front =0;
    for (int i=9;i>=0;i--){
        if (mp[i]%2 != 0){
            v[l/2] = char(i+48);
            mp[i]--;
        }
        while (mp[i] > 0){
            v[front] = char(i+48);
            v[l-front-1] = char(i+48);
            mp[i]-=2;
            front++;
        }

    }
    string res="";
    for (int i=0;i<l;i++) res+=v[i];
    return res;
}

int main(){
    cout<<max_palindrome("3322");
}
