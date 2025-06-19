class Solution {
public:
    vector<pair<int,int> > internal;
    void dfs(vector<vector<int>>& grid, int r, int c, int NewColor,int originalColor){
        if(r<0 || c<0 || r>=grid.size() || c>=grid[0].size() || grid[r][c]!=originalColor) return;
        grid[r][c]=-NewColor;
        dfs(grid,r+1,c,NewColor,originalColor);
        dfs(grid,r-1,c,NewColor,originalColor);
        dfs(grid,r,c+1,NewColor,originalColor);
        dfs(grid,r,c-1,NewColor,originalColor);

        //On returning from recurssion
        if(!(r==0 || c==0 || r==grid.size()-1 || c==grid[0].size()-1 || grid[r+1][c]!=-NewColor || grid[r-1][c]!=-NewColor || grid[r][c+1]!=-NewColor || grid[r][c-1]!=-NewColor)){
            internal.push_back({r,c});
        }
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int originalColor=grid[row][col];
        if(grid[row][col]==color) return grid;
        dfs(grid,row,col,color,originalColor);
        for(auto p:internal){
            int i=p.first;
            int j=p.second;
            grid[i][j]=originalColor;
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]<0) grid[i][j]*=-1;
            }
        }
        return grid;
    }
};