class Solution {
public:
    void dfs(vector<vector<int>>& grid,vector<vector<bool>>&vis, int row, int col, int m, int n, int currColor,int newColor){
        if(row<0 || col<0 || row>=m || col>=n || grid[row][col]!=currColor || vis[row][col]){
            return;
        }
        vis[row][col]=true;
        bool border = false;
        if(row==0 || col==0 || row==m-1 || col==n-1 || currColor!=grid[row-1][col] || currColor!=grid[row][col-1] || currColor!=grid[row][col+1] || currColor!=grid[row+1][col]){
             border=true;
        }
            dfs(grid,vis,row-1,col,m,n,currColor,newColor);
        
            dfs(grid,vis,row,col-1,m,n,currColor,newColor);
        
            dfs(grid,vis,row,col+1,m,n,currColor,newColor);
        
            dfs(grid,vis,row+1,col,m,n,currColor,newColor);   
        if(border){
            grid[row][col]=newColor;
        }
        
    }
    
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int m=grid.size();
        int n=grid[0].size();vector<vector<bool>>vis(m,vector<bool>(n,false));
        dfs(grid,vis,row,col,m,n,grid[row][col],color);
        
        return grid;
    }
    
};