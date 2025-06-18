#include<iostream>
#include<list>
#include<vector>
#include<unordered_set>
#include<queue>
using namespace std;
vector<list<int>>graph;
unordered_set<int>visited;
queue<int> qu;
int v;
void addEdge(int src,int des,bool undirected=true){
    graph[src].push_back(des);
    if(undirected){
        graph[des].push_back(src);
    }
}

void bfs(int src,int des,vector<int> &dist){
    dist.resize(v,INT_MAX);
    dist[src]=0;
    visited.clear();
    visited.insert(src);
    qu.push(src);
    while(!qu.empty()){
        int curr=qu.front();
        qu.pop();
        for(auto neighbour:graph[curr]){
            if(!visited.count(neighbour)){
                qu.push(neighbour);
                visited.insert(neighbour);
                dist[neighbour]=dist[curr]+1;
            }
        }
    }
}

int main(){
    cin>>v;
    int e;
    cin>>e;
    graph.resize(v,list<int> ());
    while(e--){
        int src,des;
        cin>>src>>des;
        addEdge(src,des);
    }
    vector<int> dist;
    int x,y;
    cin>>x>>y;
    bfs(x,y,dist);
    for(int i=0;i<dist.size();i++){
        cout<<dist[i]<<" ";
    }   
}

//input
// 7
// 8
// 0 1
// 0 4
// 4 3
// 3 1
// 1 5
// 5 6
// 5 2
// 6 2
// 0
// 2
//output
// 0 1 3 2 1 2 3 