#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int find(vector<int>&parent,int x){
    return parent[x]=(parent[x]==x)?x:find(parent,parent[x]);
}

void Union(vector<int> &parent ,vector<int> &rank,vector<int>&maximal,vector<int>&minimal,vector<int>&sz,int a,int b){
    a=find(parent,a);
    b=find(parent,b);
    if(a==b) return;
    if(rank[a]>=rank[b]){
        rank[a]++;
        parent[b]=a;
        sz[a]+=sz[b];
        minimal[a]=min(minimal[a],minimal[b]);
        maximal[a]=max(maximal[a],maximal[b]);

    }
    else{
        rank[b]++;
        parent[a]=b;
        sz[b]+=sz[a];
        minimal[b]=min(minimal[a],minimal[b]);
        maximal[b]=max(maximal[a],maximal[b]);
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int>parent(n+1);
    vector<int>rank(n+1,0);
    vector<int>sz(n+1,1);
    vector<int> maximal(n+1);
    vector<int>minimal(n+1);
    for(int i=0;i<=n;i++){
        parent[i]=maximal[i]=minimal[i]=i;
    }
    while(m--){
        string str;
        cin>>str;
        if(str=="union"){
            int x,y;
            cin>>x>>y;
            Union(parent,rank,maximal,minimal,sz,x,y);
        }
        else{
            int z;
            cin>>z;
            int x=find(parent,z);
            cout<<minimal[x]<<" "<<maximal[x]<<" "<<sz[x]<<"\n";
        }
    }

}


/* 
sample input
5 11
union 1 2
get 3
union 2 3
get 2
union 1 3
get 5
union 4 5
get 5
union 4 1
get 5

output
3 3 1
1 3 3
5 5 1
4 5 2
1 5 5
*/