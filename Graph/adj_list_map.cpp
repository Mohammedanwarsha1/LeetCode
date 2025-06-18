#include<iostream>
#include<list>
#include<vector>
#include<unordered_map>
using namespace std;
vector<unordered_map<int,int>>graph;
void addEdge(int src,int des,int wt,bool undirected=false){
    graph[src][des]=wt;
    if(undirected){
        graph[des][src]=wt;
    }
}

void display(){
    for(int i=0;i<graph.size();i++){
        cout<<i<<"-->";
        for(auto ele:graph[i]){
            cout<<"("<<ele.first<<","<<ele.second<<")";
        }
        cout<<"\n";
    }
}

int main(){
    int v;
    cin>>v;
    int e;
    cin>>e;
    graph.resize(v,unordered_map<int,int> ());
    while(e--){
        int src,des,wt;
        cin>>src>>des>>wt;
        addEdge(src,des,wt);
    }
    display();   
}