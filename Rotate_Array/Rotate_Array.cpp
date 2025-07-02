#include<bits/stdc++.h>

void Reverse_Part(vector<int> &v,int i,int j){
    while(i<=j){
        int temp=v[i];
        v[i]=v[j];
        v[j]=temp;
        i++;
        j--;
    }
    return;
}

void display(vector<int> &a){
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main(){
    
    vector<int>v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);

    display(v);

    int k=9;
    int n=v.size();
    if(k>n) k=k%n;
    Reverse_Part(v,0,n-k-1);
    Reverse_Part(v,n-k,n-1);
    Reverse_Part(v,0,n-1);

    display(v);
}