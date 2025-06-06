class Solution {
public:
    bool isSafe(vector<vector<char>> &grid, int r, int c, int num) {
        for (int i = 0; i < 9; i++) {
            if (grid[r][i] - '0' == num) return false;
            if (grid[i][c] - '0' == num) return false;
        }
        int x = (r / 3) * 3;
        int y = (c / 3) * 3;
        for (int i = x; i < x + 3; i++) {
            for (int j = y; j < y + 3; j++) {
                if (grid[i][j] - '0' == num) return false;
            }
        }
        return true;
    }
    int f(vector<vector<char>> &grid,int row,int col){
        if(row==9) return true;
        if(col==9) return f(grid,row+1,0);
        if(grid[row][col]!='.') return f(grid,row,col+1);
        for(int j=1;j<=9;j++){
            if(isSafe(grid,row,col,j)){
                grid[row][col]='0'+j;
                bool r=f(grid,row,col+1);
                if(r) return true;
                grid[row][col]='.';
            }
        }        
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        f(board,0,0);
    }
};