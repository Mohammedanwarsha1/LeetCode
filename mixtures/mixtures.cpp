#include<iostream>
#include<vector>
#include<cstring>
#include<climits>
using namespace std;

int dp[105][105];
int g(vector<int>&color,int i,int j){
    int result = 0;
    for (int m = i; m <= j; m++) {
        result += color[m];
    }
    return result % 100;
}
int f(vector<int>&color,int i,int j){
    if(i==j) return dp[i][j]=0;
    if(dp[i][j] != -1) return dp[i][j];
    int mini=INT_MAX;
    for(int k=i;k<=j-1;k++){
        mini=min(mini,f(color,i,k)+f(color,k+1,j)+g(color,i,k)*g(color,k+1,j));
    }
    return dp[i][j]=mini;
}
int main(){
    int n;
    while(cin>>n){
        vector<int>color;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            color.push_back(x);
        }
        memset(dp,-1,sizeof dp);
        cout<<f(color,0,color.size()-1)<<"\n";
        color.clear();
    }
    return 0;
}