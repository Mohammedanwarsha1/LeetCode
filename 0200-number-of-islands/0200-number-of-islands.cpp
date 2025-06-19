class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        int ct=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]=='0'){
                    continue;
                }
                ct++;
                queue<pair<int,int>>q;
                grid[i][j]='0';
                q.push({i,j});
                while(!q.empty()){
                    auto curr=q.front();
                    q.pop();
                    int currRow=curr.first;
                    int currCol=curr.second;
                    if(currRow-1>=0 && grid[currRow-1][currCol]=='1'){
                        q.push({currRow-1,currCol});
                        grid[currRow-1][currCol]='0';

                    }
                    if(currRow+1<row && grid[currRow+1][currCol]=='1'){
                        q.push({currRow+1,currCol});
                        grid[currRow+1][currCol]='0';

                    }
                    if(currCol-1>=0 && grid[currRow][currCol-1]=='1'){
                        q.push({currRow,currCol-1});
                        grid[currRow][currCol-1]='0';

                    }
                    if(currCol+1<col && grid[currRow][currCol+1]=='1'){
                        q.push({currRow,currCol+1});
                        grid[currRow][currCol+1]='0';

                    }
                }
            }
        }
        return ct;
    }
};