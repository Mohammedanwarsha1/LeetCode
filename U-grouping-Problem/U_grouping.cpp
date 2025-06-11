#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
#define ll long long int
vector<ll>dp(1<<16,INT_MAX);
vector<ll>sum(1<<16,0);

ll cal(vector<vector<ll>> &comp,int mask){
    ll ans=0;
    for(int i=0;i<=16;i++){
        for(int j=i+1;j<=16;j++){
            if(((mask & (1<<i))!=0) && ((mask & (1<<j))!=0)){
                ans+=comp[i][j];
            }
        }
    }
    return ans;
}

void precompute(vector<vector<ll>> &comp,int n){
    for(int mask=1; mask<=((1<<n)-1); mask++){
        sum[mask]=cal(comp,mask);
    }
}

ll f(vector<vector<ll>> & comp,ll mask){
    if(mask==0) return 0;
    if(dp[mask]!=INT_MAX) return dp[mask];
    ll ans=0;
    for(int g=mask;g!=0;g=((g-1) & mask)){
        ans=max(ans,sum[g] + f(comp,(mask ^ g)));
    }
    return dp[mask]=ans;
}

int main(){
    int n;
    cin>>n;
    vector<vector<ll>>comp(n,vector<ll>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>comp[i][j];
        }
    }
    precompute(comp,n);
    cout<<f(comp,((1<<n)-1));
}