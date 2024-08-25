class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<bool>> atlantic, pacific;
    void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& vis, int i,
             int j) {
        int m = matrix.size();
        int n = matrix[0].size();
        if (vis[i][j])
            return;
        vis[i][j] = true;
        if (pacific[i][j] && atlantic[i][j])
            ans.push_back({i, j});
        if (i + 1 < m && matrix[i + 1][j] >= matrix[i][j])
            dfs(matrix, vis, i + 1, j);
        if (j + 1 < n && matrix[i][j + 1] >= matrix[i][j])
            dfs(matrix, vis, i, j + 1);
        if (i - 1 >= 0 && matrix[i - 1][j] >= matrix[i][j])
            dfs(matrix, vis, i - 1, j);
        if (j - 1 >= 0 && matrix[i][j - 1] >= matrix[i][j])
            dfs(matrix, vis, i, j - 1);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        atlantic = pacific = vector<vector<bool>>(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            dfs(heights, atlantic, i, n - 1), dfs(heights, pacific, i, 0);
        }
        for (int i = 0; i < n; i++) {
            dfs(heights, atlantic, m - 1, i), dfs(heights, pacific, 0, i);
        }

        return ans;
    }
};