#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
vector<int>dp;
vector<int> get_digits(int n){
    vector<int> result;
    while(n>0){
        if(n%10!=0){
            result.push_back(n%10);
        }
        n=n/10;
    }
    return result;
}
int r_digit(int n){
    vector<int>digit=get_digits(n);
    if(n==0) return 0;
    if(n<=9) return 1;
    if(dp[n]!=-1) return dp[n];
    int mini=INT_MAX;
    for(int d:digit){
        mini=min(mini,r_digit(n-d));
    }
    return dp[n]=1+mini;
    
}
int main(){
    int n;
    cin>>n;
    dp.clear();
    dp.resize(1000005,-1);
    cout<<r_digit(n)<<"\n";
}