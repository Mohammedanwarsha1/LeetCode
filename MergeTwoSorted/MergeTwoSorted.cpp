#include<bits/stdc++.h>

vector<int> merge(vector<int> &arr1,vector<int> &arr2){
    int i=0;int j=0;int k=0;
    int n=arr1.size();
    int m=arr2.size();
    vector<int>res(m+n);
    while(i<=n-1 && j<=m-1){
        if(arr1[i]<arr2[j]){
            res[k]=arr1[i];
            i++;
        }
        else{
            res[k]=arr2[j];
            j++;
        }
        k++;
    }
    if(i==n){
        while(j<=m-1){
            res[k]=arr2[j];
            k++;
            j++;
        }
    }
    if(j==m){
        while(i<=n-1){
            res[k]=arr1[i];
            k++;
            i++;
        }
    }
    return res;
}

void display(vector<int> &v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int>arr1;
    arr1.push_back(1);
    arr1.push_back(2);
    arr1.push_back(3);
    arr1.push_back(4);
    arr1.push_back(5);
    arr1.push_back(6);
    display(arr1);

    vector<int>arr2;
    arr2.push_back(7);
    arr2.push_back(8);
    arr2.push_back(9);
    arr2.push_back(10);
    arr2.push_back(11);
    arr2.push_back(12);
    arr2.push_back(13);
    arr2.push_back(14);
    display(arr2);

    vector<int> res=merge(arr1,arr2);
    display(res);
}