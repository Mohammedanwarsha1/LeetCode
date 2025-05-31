#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int f(vector<int> &arr){
    int cz=0,cp=0,cn=0,largest_neg,prod_n=1,prod_p=1;
    largest_neg=INT_MIN;
    for(int i=0;i<arr.size();i++){
        if(arr[i]<0){
            cn++;
            prod_n*=arr[i];
            largest_neg=max(largest_neg,arr[i]);
        }
        else if(arr[i]>0){
            cp++;
            prod_p*=arr[i];
        }
        else cz++;
    }
    if(cn==0){
        if(cz>0) return 0;
        else{
            auto it= min_element(arr.begin(),arr.end());
            return *it;
        }
    }
    else{
        if(cn%2==0) return (prod_n/largest_neg)*prod_p;
        else return prod_n*prod_p;
    }
}

int main(){
    vector<int>arr {-2,-3,1,4,-2};
    cout<<f(arr)<<"\n";
    return 0;
}