#include<iostream>
#include<vector>
using namespace std;
vector<vector<char>>grid;
vector<vector<string>>result;
void f(int row,int n,int colMask,int disMask,int antiDiaMask){
    if(row==n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    for(int col=0;col<n;col++){
        int colBit = 1<<col;
        int diaBit = 1<<(row-col+n-1);
        int AntiDiaBit = 1<<(row+col);
        if((colMask & colBit) || (disMask & diaBit) || (antiDiaMask & AntiDiaBit)){
            continue;
        }
        grid[row][col]='Q';
        f(row+1,n,(colMask | colBit),(disMask | diaBit),(antiDiaMask | AntiDiaBit));
        grid[row][col]='.';
    }
}

vector<vector<string>> N_Queen(int n){
    grid.clear();
    result.clear();
    grid.resize(n, vector<char>(n, '.'));
    f(0,n,0,0,0);
    return result;
}

int main(){
    int n;
    cin>>n;
    N_Queen(n);
}