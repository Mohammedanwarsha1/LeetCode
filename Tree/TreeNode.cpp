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

void displayNode(TreeNode * root){
    if(root==NULL) return;
    cout<<root->val<<" ";
    displayNode(root->left);
    displayNode(root->right);
}

int sumNode(TreeNode * root)
{
    if(root==NULL) return 0;
    return root->val + sumNode(root->left) + sumNode(root->right);
}

int size(TreeNode * root){
    if(root==NULL) return 0;
    return 1+size(root->left)+size(root->right);  //'1' indicates size of each node
}

int NodeMax(TreeNode * root){
    if(root==NULL) return INT_MIN;
    int leftMax=NodeMax(root->left);
    int rightMax=NodeMax(root->right);
    return max(root->val,max(leftMax,rightMax));
}

int level(TreeNode* root)
{
    if(root==NULL) return 0;
    return 1 + max(level(root->left),level(root->right));
}

void nthlevel(TreeNode*root,int currLevel,int targetLevel){
    if(root==NULL) return;
    if(currLevel==targetLevel){
        cout<<root->val<<" ";
    }
    nthlevel(root->left,currLevel+1,targetLevel);
    nthlevel(root->right,currLevel+1,targetLevel);
}
void nthlevelRev(TreeNode*root,int currLevel,int targetLevel){
    if(root==NULL) return;
    if(currLevel==targetLevel){
        cout<<root->val<<" ";
    }
    nthlevelRev(root->right,currLevel+1,targetLevel);
    nthlevelRev(root->left,currLevel+1,targetLevel);
}

void levelOrdeerTraversal(TreeNode* root){
    int n=level(root);
    for(int i=1;i<=n;i++){
        nthlevelRev(root,1,i);
        cout<<endl;
    }
}
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


int main(){
    TreeNode* a=new TreeNode(1);
    TreeNode* b=new TreeNode(2);
    TreeNode* c=new TreeNode(3);
    TreeNode* d=new TreeNode(4);
    TreeNode* e=new TreeNode(5);
    TreeNode* f=new TreeNode(6);
    TreeNode* g=new TreeNode(7);

    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;

    displayNode(a);
    cout<<endl;
    cout<<sumNode(a);
    cout<<endl;
    cout<<size(a);
    cout<<endl;
    cout<<NodeMax(a);
    cout<<endl;
    cout<<level(a);
    cout<<endl;
    cout<<endl;
    //nthlevel(a,1,2);
    //levelOrdeerTraversal(a);
    levelOrderQueue(a);
}