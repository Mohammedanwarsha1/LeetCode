class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color) return image;
        dfs(image,sr,sc,image[sr][sc],color);
        return image;
    }
    void dfs(vector<vector<int>>& image,int currRow,int currCol,int inisialCol,int newColor){
        
        int n=image.size();
        int m=image[0].size();
        if(currRow<0 || currCol<0 || currRow>=n || currCol>=m) return;
        if(image[currRow][currCol]!=inisialCol) return;
        image[currRow][currCol]=newColor;
        dfs(image,currRow+1,currCol,inisialCol,newColor);
        dfs(image,currRow,currCol+1,inisialCol,newColor);
        dfs(image,currRow-1,currCol,inisialCol,newColor);
        dfs(image,currRow,currCol-1,inisialCol,newColor);
    }
};