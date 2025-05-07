class Solution {
public:
    void helper(TreeNode * root,long long target,int &count){
        if(root==NULL) return;
        if((long long)root->val==target) count++;
        helper(root->left,target-(long long)(root->val),count);
        helper(root->right,target-(long long)(root->val),count);
    }
    int pathSum(TreeNode* root, int targetSum) {
        int count=0;
        if(root==NULL) return 0;
        helper(root,targetSum,count);
        count+=(pathSum(root->left,targetSum)+pathSum(root->right,targetSum));
        return count;
    }
};