#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;
void permutation(string &str,int i){
    if(i==str.size()-1){
        cout<<str<<"\n";
        return;
    }
    unordered_set<char>s;
    for(int idx=i;idx<str.size();idx++){
        if(s.count(str[idx]))continue;
        s.insert(str[idx]);
        swap(str[idx],str[i]);  //here we swap original string also get changed(passbyReference)so we need to re-swap it inordered to nullify the change made
        permutation(str,i+1);
        swap(str[idx],str[i]);  //backtracking step
    }
}
int main(){
    string str="aba";
    permutation(str,0);
}