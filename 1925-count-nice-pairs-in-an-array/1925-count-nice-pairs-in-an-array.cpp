class Solution {
public:
    int fact(int n){
        int f=1;
        for(int i=2;i<=n;i++){
            f*=i;
        }
        return f;
    }
    int combi(int n,int r){
        return fact(n)/(fact(r)*fact(n-r));
    }
    int reverse(int n){
        int r=0;
        while(n>0){
            r*=10;
            r+=(n%10);
            n/=10;
        }
        return r;
    }
    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int>mp;
        int count=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums[i]=nums[i]-reverse(nums[i]);
        }
        for(int i=0;i<n;i++){
            if(mp.find(nums[i])!=mp.end()){
                count=count%1000000007;
                count+=mp[nums[i]];
            }
            mp[nums[i]]++;
        }
        return count%1000000007;
    }
};