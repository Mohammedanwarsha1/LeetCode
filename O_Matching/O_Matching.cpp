#include<iostream>
#include<vector>
#include<climits>
#include<cstring>
using namespace std;
#define mod 100000007
int dp[22][1<<22];
int f(int i,int mask,int n,vector<vector<int>> &c){
    if(i==n+1){
        if(mask==0) return 1;
        return 0;
    }
    if(dp[i][mask]!=-1) return dp[i][mask];
    int ans=0;
    for(int w=1;w<=n;w++){
        bool avail=(((1<<(w-1)) & mask)==0)?0:1;
        if(avail && c[i][w]){
            ans=((ans%mod)+(f(i+1,(mask ^ (1<<(w-1))),n,c))%mod)%mod;
        }
    }
    return dp[i][mask]=ans;
}
int main(){
    int n;
    cin>>n;
    memset(dp,-1,sizeof dp);
    vector<vector<int>>c(n+1,vector<int>(n+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>c[i][j];
        }
    }
    cout<<f(1,(1<<n)-1,n,c)<<" ";
}