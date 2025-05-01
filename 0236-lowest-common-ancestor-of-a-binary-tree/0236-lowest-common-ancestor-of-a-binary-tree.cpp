class Solution {
public:
    bool exist(TreeNode * root,TreeNode * target){
        if(root==NULL) return false;
        if(root==target) return true;
        return exist(root->left,target) || exist(root->right,target);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==p || root==q) return root;
        else if(exist(root->left,p) && exist(root->right,q)) return root;
        else if(exist(root->right,p) && exist(root->left,q)) return root;
        else if(exist(root->left,p) && exist(root->left,q)) return lowestCommonAncestor(root->left,p,q);
        else return lowestCommonAncestor(root->right,p,q);
    }
};