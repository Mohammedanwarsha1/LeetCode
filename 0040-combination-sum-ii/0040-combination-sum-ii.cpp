class Solution {
public:
    vector<vector<int> > result;
    void f(vector<int>&candidate,int t,int idx,vector<int>&subset){
        if(t==0){
            result.push_back(subset);
            return;
        }
        if(idx==candidate.size()) return;
        if(candidate[idx]<=t){
            subset.push_back(candidate[idx]);
            f(candidate,t-candidate[idx],idx+1,subset);
            subset.pop_back();
        }
        int j=idx+1;
        while(j<candidate.size() && candidate[j]==candidate[j-1]) j++;
        f(candidate,t,j,subset);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> subset;
        sort(candidates.begin(),candidates.end());
        result.clear();
        f(candidates,target,0,subset);
        return result;
    }
};