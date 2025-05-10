class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;
        while (curr != NULL) {
            if (curr->left != NULL) {
                TreeNode* pred = curr->left;
                while (pred->right != NULL && pred->right != curr) {
                    pred = pred->right;
                }
                if (pred->right == NULL) {
                    pred->right = curr;
                    curr = curr->left;
                } else {
                    pred->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }

            } else {
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
        return ans;
    }
};

// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         stack<TreeNode*>st;
//         vector<int> ans;
//         TreeNode * node=root;
//         while(st.size()>0 || node!=NULL){
//             if(node){
//                 st.push(node);
//                 node=node->left;
//             }
//             else{
//                 TreeNode * temp=st.top();
//                 st.pop();
//                 ans.push_back(temp->val);
//                 node=temp->right;
//             }
//         }
//         return ans;
//     }
// };