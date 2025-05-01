class Solution {
public:
    void helper(TreeNode * root,int &maxDia){
        if(root==NULL) return;
        int dia=level(root->left) + level(root->right);
        maxDia=max(dia,maxDia);
        helper(root->left,maxDia);
        helper(root->right,maxDia);
    }
    int level(TreeNode * root){
        if(root==NULL) return 0;
        return 1+max(level(root->left),level(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDia=0;  // Reinisialize
        helper(root,maxDia);
        return maxDia;
    }
};







// with global variable
// class Solution {
// public:
//     int maxDia=0;
//     int level(TreeNode * root){
//         if(root==NULL) return 0;
//         return 1+max(level(root->left),level(root->right));
//     }
//     int diameterOfBinaryTree(TreeNode* root) {
//         if(root==NULL) return 0;
//         int dia=level(root->left) + level(root->right);
//         maxDia=max(dia,maxDia);
//         diameterOfBinaryTree(root->left);
//         diameterOfBinaryTree(root->right);
//         return maxDia;
//     }
// };