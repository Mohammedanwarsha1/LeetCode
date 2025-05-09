class Solution {
public:
    TreeNode *inopre(TreeNode * root){
        TreeNode * pre=root->left;
        while(pre->right!=NULL){
            pre=pre->right;
        }
        return pre;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(root->val==key){
            // deleteion of leaf node
            if(root->left==NULL && root->right==NULL) return NULL;
            //deleteion of node having one child
            if(root->left==NULL || root->right==NULL){
                if(root->left!=NULL){
                    return root->left;
                }
                else return root->right;
            }
            //deleteion of node having two child
            if(root->left!=NULL && root->right!=NULL){
                TreeNode* pre=inopre(root);
                root->val=pre->val;
                root->left=deleteNode(root->left,pre->val);
            }
        }
        else if(root->val>key) root->left=deleteNode(root->left,key);
        else root->right=deleteNode(root->right,key);
        return root;
    }
};