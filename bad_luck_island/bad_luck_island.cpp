#include<iostream>
#include<vector>
#include<iomanip>
#include<cstring>
#include<climits>
using namespace std;
#define ld long double
ld dp[105][105][105];
ld fr(int r,int p,int s){
    if(p==0) return 1;
    if(s==0) return 0;
    if(r==0) return 0;
    if(dp[r][p][s]>-0.9) return dp[r][p][s];
    ld total=r*s+r*p+p*s;
    ld ans=0.0;
    ans+=fr(r,p,s-1)*((r*s)/total);
    ans+=fr(r-1,p,s)*((r*p)/total);
    ans+=fr(r,p-1,s)*((p*s)/total);
    return dp[r][p][s]=ans;
}
ld fp(int r,int p,int s){
    if(s==0) return 1;
    if(r==0) return 0;
    if(p==0) return 0;
    if(dp[r][p][s]>-0.9) return dp[r][p][s];
    ld total=r*s+r*p+p*s;
    ld ans=0.0;
    ans+=fp(r,p,s-1)*((r*s)/total);
    ans+=fp(r-1,p,s)*((r*p)/total);
    ans+=fp(r,p-1,s)*((p*s)/total);
    return dp[r][p][s]=ans;
}

ld fs(int r,int p,int s){
    if(r==0) return 1;
    if(p==0) return 0;
    if(s==0) return 0;
    if(dp[r][p][s]>-0.9) return dp[r][p][s];
    ld total=r*s+r*p+p*s;
    ld ans=0.0;
    ans+=fs(r,p,s-1)*((r*s)/total);
    ans+=fs(r-1,p,s)*((r*p)/total);
    ans+=fs(r,p-1,s)*((p*s)/total);
    return dp[r][p][s]=ans;
}


int main(){
    int r,p,s;
    cin>>r>>p>>s;
    memset(dp,-1,sizeof dp);
    ld ans_r=fr(r,p,s);
    memset(dp,-1,sizeof dp);
    ld ans_p=fp(r,s,p);
    memset(dp,-1,sizeof dp);
    ld ans_s=fs(r,s,p);
    cout<<fixed<<setprecision(9)<<ans_r<<" "<<ans_p<<" "<<ans_s;


}