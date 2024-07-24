class Solution {
public:
    int helper(int i, int j, vector<vector<int>>& triangle, int n, vector<vector<int>>& dp){
        if(i>=n){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int l = triangle[i][j]+helper(i+1,j,triangle,n,dp);
        int r = triangle[i][j]+helper(i+1,j+1,triangle,n,dp);
        return dp[i][j]=min(l,r);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            dp[n-1][i]=triangle[n-1][i];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                dp[i][j]=triangle[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
            }
        }
        return dp[0][0];
        //return helper(0,0,triangle,n,dp);

    }
}; 