class Solution {
public:
    int level(TreeNode* root)
    {
        if(root==NULL) return 0;
        return 1 + max(level(root->left),level(root->right));
    }

    void nthlevel(TreeNode*root,int currLevel,int Level,vector<int> &ans){
        if(root==NULL) return;
        if(currLevel==Level){
            ans[currLevel]=root->val;
            return;
        }
        nthlevel(root->left,currLevel+1,Level,ans);
        nthlevel(root->right,currLevel+1,Level,ans);
    }
    void levelOrdeerTraversal(TreeNode* root,vector<int> &ans){
        int n=ans.size();
        for(int i=0;i<n;i++){
            nthlevel(root,0,i,ans);
        }
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans(level(root),0);
        levelOrdeerTraversal(root,ans);
        return ans;
    }
};