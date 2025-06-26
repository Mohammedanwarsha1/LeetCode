#include <bits/stdc++.h>
#include<iostream>
using namespace std;
vector<list<int>>graph;
void addEdge(int src,int des,bool undirected=true){
    graph[src].push_back(des);
    if(undirected){
        graph[des].push_back(src);
    }
}

void TopSort(vector<int>&indegree){
    for(int i=0;i<graph.size();i++){
        for(auto neighboure:graph[i]){
            indegree[neighboure]++;
        }
    }
    queue<int>qu;
    unordered_set<int>vis;
    for(int i=0;i<indegree.size();i++){
        if(indegree[i]==0){
            qu.push(i);
            vis.insert(i);
        }
    }
    while(!qu.empty()){
        int ele=qu.front();
        cout<<ele<<" ";
        qu.pop();
        for(auto neighboure:graph[ele]){
            if(!vis.count(neighboure)){
                indegree[neighboure]--;
                if(indegree[neighboure]==0){
                    qu.push(neighboure);
                    vis.insert(neighboure);
                }
            }
            
        }
        

    }
    
}

int main(){
    int v;
    cin>>v;
    int e;
    cin>>e;
    vector<int>indegree(v,0);
    graph.resize(v,list<int> ());
    while(e--){
        int src,des;
        cin>>src>>des;
        addEdge(src,des,false);
    }  
    TopSort(indegree);
}
