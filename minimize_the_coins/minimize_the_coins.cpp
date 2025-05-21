#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
vector<int>coins;
vector<int>dp(1000005,-1);
int f(int x){
    if(x==0) return 0;
    if(dp[x]!=-1) return dp[x];
    int mini=INT_MAX;
    for(int i=0;i<coins.size();i++){
        if((x-coins[i])<0) continue;
        mini=min(mini,f(x-coins[i]));
    }
    if(mini==INT_MAX) return dp[x]=INT_MAX;
    return dp[x]=1+mini;
}

int main(){
    int n,x;
    cin>>n>>x;
    for(int i=0;i<n;i++){
        int nums;
        cin>>nums;
        coins.push_back(nums);
    }
    int ans=f(x);
    if(ans==INT_MAX){
        cout<<-1;
    }
    else{
        cout<<ans<<endl;
    }
    return 0;
}