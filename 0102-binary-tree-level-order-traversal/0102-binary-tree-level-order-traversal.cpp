class Solution {
public:
    int level(TreeNode* root)
    {
        if(root==NULL) return 0;
        return 1 + max(level(root->left),level(root->right));
    }

    void nthlevel(TreeNode*root,int currLevel,int targetLevel,vector<int> &v){
        if(root==NULL) return;
        if(currLevel==targetLevel){
            v.push_back(root->val);
        }
        nthlevel(root->left,currLevel+1,targetLevel,v);
        nthlevel(root->right,currLevel+1,targetLevel,v);
    }
    void lOrder(TreeNode* root,vector<vector<int>> &ans){
        int n=level(root);
        for(int i=1;i<=n;i++){
            vector<int> v;
            nthlevel(root,1,i,v);
            ans.push_back(v);
        }
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        lOrder(root,ans);
        return ans;
        
    }
};