class Solution {
public:
    int helper(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(i>=0 && j>=0 && dp[i][j]!=-1){
            return dp[i][j];

        }
        if(i==0 && j==0){
            return grid[i][j];
        }
        if(i<0 || j<0){
            return 1e9;
        }
        
        int x= min(helper(i-1,j,grid,dp),helper(i,j-1,grid,dp));
        
        return dp[i][j]=grid[i][j]+x;
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();

        vector<vector<int>>dp(m,vector<int>(n,-1));
        return helper(m-1,n-1,grid,dp);
    }
};