#include<iostream>
#include<vector>
using namespace std;
bool canWeGo(vector<vector<int>> &grid,int i,int j,int n){
    return i>=0 && j>=0 && j<n && i<n && grid[i][j]==0;
}

void ratInAMaze(vector<vector<int>> &grid,int i,int j,int n,int &ans){
    if(i==n-1 && j==n-1){
        ans+=1;
        return;
    }

    grid[i][j]=2;

    //left
    if(canWeGo(grid,i,j-1,n)){
        ratInAMaze(grid,i,j-1,n,ans);
    }
    //up
    
    if(canWeGo(grid,i-1,j,n)){
        ratInAMaze(grid,i-1,j,n,ans);
    }
    //right
    
    if(canWeGo(grid,i,j+1,n)){
        ratInAMaze(grid,i,j+1,n,ans);
    }
    //down
    
    if(canWeGo(grid,i+1,j,n)){
        ratInAMaze(grid,i+1,j,n,ans);
    }
    grid[i][j]=0;
}
int main() {
    int ans = 0;
    vector<vector<int>> grid = {
        {0, 0, 0, 0},
        {0, 1, 0, 1},
        {0, 1, 0, 0},
        {0, 0, 0, 0}
    };
    if (grid[0][0] == 0)
        ratInAMaze(grid, 0, 0, 4, ans);
    cout << ans << endl;
}