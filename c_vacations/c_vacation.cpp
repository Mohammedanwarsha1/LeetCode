#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a,b,c;
    cin>>a>>b>>c;
    vector<vector<int>>d(n,vector<int>(3,0));
    d[0][0]=a;
    d[0][1]=b;
    d[0][2]=c;
    for(int i=1;i<n;i++){
        cin>>a>>b>>c;
        d[i][0]=a+max({d[i-1][1],d[i-1][2]});
        d[i][1]=b+max({d[i-1][0],d[i-1][2]});;
        d[i][2]=c+max({d[i-1][0],d[i-1][1]});;
    }
    cout<<max({d[n-1][0],d[n-1][1],d[n-1][2]});


}