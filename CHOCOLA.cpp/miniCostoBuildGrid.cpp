#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long int

bool cmp(int x,int y){
    return x > y;
}

ll miniCostGrid(int n,int m,vector<ll>&vertical,vector<ll>&horizontal){
    sort(vertical.begin(),vertical.end(),cmp);
    sort(horizontal.begin(),horizontal.end(),cmp);
    int hz=1;
    int vr=1;
    int h=0;
    int v=0;
    ll ans=0;
    while((h<horizontal.size())&&(v<vertical.size())){
        if(vertical[v]>horizontal[h]){
            ans+=vertical[v]*vr;
            hz++;

            v++;
        }else{
            ans+=horizontal[h]*hz;
            vr++;

            h++;
        }
    }
    while(h<horizontal.size()){
        ans+=horizontal[h]*hz;
        vr++;

        h++;
    }
    while(v<vertical.size()){
        ans+=vertical[h]*vr;
        hz++;

        v++;
    }
    return ans;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<ll>vertical,horizontal;
    for(int i=0;i<n-1;i++){
        int x;
        cin>>x;
        vertical.push_back(x);
    }
    for(int i=0;i<m-1;i++){
        int x;
        cin>>x;
        horizontal.push_back(x);
    }
    cout<<miniCostGrid(n,m,vertical,horizontal);
    return 0;
}