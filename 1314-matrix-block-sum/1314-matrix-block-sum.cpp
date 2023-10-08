class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>ans(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                ans[i][j]=ans[i-1][j]+ans[i][j-1]-ans[i-1][j-1]+mat[i-1][j-1];
            }        
        }
        // int[][] ans = new int[m][n];
        // for (int r = 0; r < m; r++) {
        //     for (int c = 0; c < n; c++) {
        //         int r1 = Math.max(0, r - K), c1 = Math.max(0, c - K);
        //         int r2 = Math.min(m - 1, r + K), c2 = Math.min(n - 1, c + K);
        //         r1++; c1++; r2++; c2++; // Since `sum` start with 1 so we need to increase r1, c1, r2, c2 by 1
        //         ans[r][c] = sum[r2][c2] - sum[r2][c1-1] - sum[r1-1][c2] + sum[r1-1][c1-1];
        //     }
        // }
        // return ans;
        vector<vector<int>>sum(m,vector<int>(n,0));
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                int r1 = max(0, r - k), c1 = max(0, c - k);
                int r2 = min(m - 1, r + k), c2 = min(n - 1, c + k);
                r1++; c1++; r2++; c2++;
                sum[r][c]=ans[r2][c2]-ans[r2][c1-1]-ans[r1-1][c2]+ans[r1-1][c1-1];
                
            }
        }
        return sum;
    }
};