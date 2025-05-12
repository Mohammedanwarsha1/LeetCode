#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Node{
public:
    Node* left;
    Node*right;
    int val;
    Node(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};
void inorder(Node * root,vector<int> &dec){
    if(root==NULL) return;
    inorder(root->right,dec);
    dec.push_back(root->val);
    inorder(root->left,dec);
}
void print(vector<int> &v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
void preorder(Node* root,vector<int> &arr,int &i){
    if(root==NULL) return;
    root->val=arr[i++];
    preorder(root->left,arr,i);
    preorder(root->right,arr,i);

}
void levelOrderQueue(Node * root){
    queue<Node*> q;
    q.push(root);
    while(q.size()>0){
        Node* temp=q.front();
        q.pop();
        cout<<temp->val<<" ";
        if(temp->left!=NULL) q.push(temp->left);
        if(temp->right!=NULL) q.push(temp->right);
    }
    cout<<endl;
}
int main(){
    Node *a=new Node(10);
    Node *b=new Node(5);
    Node *c=new Node(16);
    Node *d=new Node(1);
    Node *e=new Node(8);
    Node *f=new Node(12);
    Node *g=new Node(20);
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;
    vector<int>dec;
    inorder(a,dec);
    levelOrderQueue(a);
    int i=0;
    preorder(a,dec,i);
    levelOrderQueue(a);
}