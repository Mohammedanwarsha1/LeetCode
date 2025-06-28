#include<bits/stdc++.h>
#define ll long long int
int find(vector<int>&parent,int x){
    return parent[x]=(parent[x]==x)?x:find(parent,parent[x]);
}

void Union(vector<int> &parent ,vector<int> &rank,int a,int b){
    a=find(parent,a);
    b=find(parent,b);
    if(a==b) return;
    if(rank[a]>=rank[b]){
        rank[a]++;
        parent[b]=a;
    }
    else{
        rank[b]++;
        parent[a]=b;
    }
}

struct Edge{
    int src;
    int des;
    int weig;
};

bool cmp(Edge a,Edge b){
    return a.weig < b.weig;
}

ll kruskal(vector<Edge>&input,int n,int e){
    sort(input.begin(),input.end(),cmp);
    vector<int>parent(n+1);
    vector<int>rank(n+1,1);
    for(int i=0;i<=n;i++){
        parent[i]=i;
    }
    int edgeCount=0;
    int i=0;
    ll ans=0;
    while(edgeCount<n-1 && i<input.size()){
        Edge curr=input[i];
        int srcParent=find(parent,curr.src);
        int desParent=find(parent,curr.des);
        if(srcParent != desParent){
            Union(parent,rank,srcParent,desParent);
            ans+=curr.weig;
            edgeCount++;
        }
        i++;
    }
    return ans;
}


int main(){
    int n,e;
    cin>>n>>e;
    vector<Edge>v(e);
        for(int i=0;i<e;i++){
            cin>>v[i].src>>v[i].des>>v[i].weig;
        }
    cout<<kruskal(v,n,e)<<"\n";


}