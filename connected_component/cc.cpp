#include<iostream>
#include<list>
#include<vector>
#include<unordered_set>
#include<queue>
using namespace std;
vector<list<int>>graph;
int v;
void addEdge(int src,int des,bool undirected=true){
    graph[src].push_back(des);
    if(undirected){
        graph[des].push_back(src);
    }
}

void dfs(int node,unordered_set<int> &visited){
    visited.insert(node);
    for(auto neighbore:graph[node]){
        if(!visited.count(neighbore)){
            dfs(neighbore,visited);
        }
    }
}

int connected_component(){
    int result=0;
    unordered_set<int>visited;
    for(int i=0;i<v;i++){
        if(visited.count(i)==0){
            result++;
            dfs(i,visited);
        }
    }
    return result;
}

int main(){
    cin>>v;
    int e;
    cin>>e;
    graph.resize(v,list<int> ());
    while(e--){
        int src,des;
        cin>>src>>des;
        addEdge(src,des,false);
    }   
    cout<<connected_component()<<"\n";
}