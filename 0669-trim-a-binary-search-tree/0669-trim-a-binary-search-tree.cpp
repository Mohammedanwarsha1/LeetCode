class Solution {
public:
    void trim(TreeNode* root,int l0,int hi){
        if(root==NULL) return;
        while(root->left!=NULL){
            if(root->left->val< l0) root->left=root->left->right;
            else if(root->left->val > hi) root->left=root->left->left;
            else break;
        }
        while(root->right!=NULL){
            if(root->right->val > hi) root->right=root->right->left;
            else if(root->right->val < l0) root->right=root->right->right;
            else break;
        }
        trim(root->left,l0,hi);
        trim(root->right,l0,hi);
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        TreeNode* dummy=new TreeNode(INT_MAX);
        dummy->left=root;
        trim(dummy,low,high);
        return dummy->left;
    }
};