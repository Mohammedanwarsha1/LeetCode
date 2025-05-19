class Solution {
public:
    vector<int>dp;
    int f(vector<int>arr,int i){
        int n=arr.size();
        if(i==n-1) return arr[i];
        if(i==n-2) return max(arr[i],arr[i+1]);
        if(dp[i]!=-1) return dp[i];
        return dp[i]=max(arr[i]+f(arr,i+2),0+f(arr,i+1));
    }
    int rob(vector<int>& nums) {
        dp.clear();
        dp.resize(105,-1);
        int n=nums.size();
        int k=f(nums,0);
        return k;
    }
};