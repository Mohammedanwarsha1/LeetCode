#include<iostream>
#include<math.h>
#include<queue>
#include<unordered_map>
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
void topViewBT(TreeNode*root){
    unordered_map<int,int>mp;
    queue< pair<TreeNode*,int> >q;
    pair<TreeNode*,int> r;
    r.first = root;
    q.push(r);
    while(q.size()>0){
        TreeNode*temp=(q.front()).first;
        int level=(q.front()).second;
        q.pop();
        if(mp.find(level)==mp.end()){
            mp[level]=temp->val;
        }
        if(temp->left!=NULL){
            pair<TreeNode*,int> p;
            p.first = temp->left;
            p.second=level-1;
            q.push(p);
        }
        if(temp->right!=NULL){
            pair<TreeNode*,int> p;
            p.first = temp->right;
            p.second=level+1;
            q.push(p);
        }

    }
    int minLevel=INT_MAX;
    int maxLevel=INT_MIN;
    for(auto x:mp){
        int level=x.first;
        minLevel=min(minLevel,level);
        maxLevel=max(maxLevel,level);
    }
    for(int i=minLevel;i<=maxLevel;i++){
        cout<<mp[i]<<" ";
    }
    cout<<endl;

}

int main(){
    int arr[]={1,2,3,4,5,INT_MIN,6,INT_MIN,INT_MIN,7,8};
    int n=sizeof(arr)/sizeof(arr[0]);
    TreeNode * root=construct(arr,n);
    topViewBT(root);
    levelOrderQueue(root);
}