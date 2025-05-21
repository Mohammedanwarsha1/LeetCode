#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#define ll long long int
#define mod 1000000007
using namespace std;
vector<ll>dp(1000005,-1);

ll f(int n){
    if(n==0) return 1;
    if(dp[n]!=-1)return dp[n];
    ll sum=0;
    for(int i=1;i<=6;i++){
        if(n-i < 0) break;
        sum=(sum%mod +f(n-i)%mod)%mod;
    }
    return dp[n]=sum%mod;

}

int main(){
    int n;
    cin>>n;
    cout<<f(n)<<"\n";
    return 0;
}