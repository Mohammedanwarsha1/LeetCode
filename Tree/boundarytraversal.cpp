#include<iostream>
#include<math.h>
#include<queue>
using namespace std;
class TreeNode{
    public:
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int val){
            this->val=val;
            this->left=NULL;
            this->right=NULL;
        }
};
void levelOrderQueue(TreeNode * root){
    queue<TreeNode*> q;
    q.push(root);
    while(q.size()>0){
        TreeNode* temp=q.front();
        q.pop();
        cout<<temp->val<<" ";
        if(temp->left!=NULL) q.push(temp->left);
        if(temp->right!=NULL) q.push(temp->right);
    }
    cout<<endl;
}

TreeNode *construct(int arr[],int n){
    if(n==0) return NULL;

    queue<TreeNode*> q;
    TreeNode* root=new TreeNode(arr[0]);
    q.push(root);
    int i=1,j=2;
    while(q.size()>0 && i<n){
        TreeNode * temp=q.front();
        q.pop();
        TreeNode * l;
        TreeNode * r;
        if(arr[i]!=INT_MIN) l=new TreeNode(arr[i]);
        else l=NULL;
        if(j!=n && arr[j]!=INT_MIN) r=new TreeNode(arr[j]);
        else r=NULL;
        temp->left=l;
        temp->right=r;
        if(l !=NULL) q.push(l);
        if(r !=NULL) q.push(r);
        
        i += 2;
        j += 2;

    }
    return root;
}
void leftBoundary(TreeNode*root){
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL) return;
    cout<<root->val<<" ";
    leftBoundary(root->left);
    if(root->left==NULL) leftBoundary(root->right);
}
void bottomBoundary(TreeNode* root){
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL) cout<<root->val<<" ";
    bottomBoundary(root->left);
    bottomBoundary(root->right);
}
void rightBoundary(TreeNode*root){
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL) return;
    rightBoundary(root->right);
    if(root->right==NULL) rightBoundary(root->left);
    cout<<root->val<<" ";
}
void boundary(TreeNode*root){
    leftBoundary(root);
    bottomBoundary(root);
    rightBoundary(root->right);
}

int main(){
    int arr[]={1,2,3,4,5,INT_MIN,6,7,INT_MIN,8,INT_MIN,9,10,INT_MIN,11,INT_MIN,12,INT_MIN,13,INT_MIN,14,15,16,INT_MIN,17,INT_MIN,INT_MIN,18,INT_MIN,19,INT_MIN,INT_MIN,INT_MIN,20,21,22,23,INT_MIN,24,25,26,29,INT_MIN,INT_MIN,28};
    int n=sizeof(arr)/sizeof(arr[0]);
    TreeNode * root=construct(arr,n);
    //levelOrderQueue(root);
    boundary(root);
}