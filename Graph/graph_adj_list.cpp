#include<iostream>
#include<list>
#include<vector>
using namespace std;
vector<list<int>>graph;
void addEdge(int src,int des,bool undirected=true){
    graph[src].push_back(des);
    if(undirected){
        graph[des].push_back(src);
    }
}

void display(){
    for(int i=0;i<graph.size();i++){
        cout<<i<<"-->";
        for(auto ele:graph[i]){
            cout<<ele<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    int v;
    cin>>v;
    int e;
    cin>>e;
    graph.resize(v,list<int> ());
    while(e--){
        int src,des;
        cin>>src>>des;
        addEdge(src,des);
    }
    display();   
}