class Solution {
public:
int sum=0;
    void RevInorder(TreeNode* root){
        if(root==NULL) return;
        RevInorder(root->right);
        root->val+=sum;
        sum=root->val;
        RevInorder(root->left);
    }
    TreeNode* bstToGst(TreeNode* root) {
        RevInorder(root);
        return root;
        
    }
};