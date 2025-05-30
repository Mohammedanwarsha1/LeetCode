#include<iostream>
#include<vector>
#include<climits>
#include<cstring>
using namespace std;
int dp[10005][105];
int n;
vector<pair<int, int>>p;
int f(int i,int x){
    if(i==n) return 0;
    if(dp[i][x]!=-1) return dp[i][x];
    int ans=INT_MAX;
    if(x==0){
        ans=p[i].second + f(i+1,x+1);
    }
    else if(x==n-i){
        ans=p[i].first + f(i+1,x-1);
    }
    else ans=min(p[i].first+f(i+1,x-1),p[i].second+f(i+1,x+1));
    return dp[i][x]=ans;
}


int main(){
    cin>>n;
    p.resize(n);
    for(int i=0;i<n;i++){
        cin >> p[i].first >> p[i].second;
    }
    memset(dp,-1,sizeof dp);
    cout<<f(0,0)<<endl;
    return 0;
}