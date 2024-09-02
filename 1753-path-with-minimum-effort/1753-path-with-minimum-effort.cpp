class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
         priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>q;
        q.push({0, {0, 0}});
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        vector<vector<int>> ans(n,vector<int> (m,1e9));
        ans[0][0]=0;
        while (!q.empty()) {
            int dist = q.top().first;
            int x = q.top().second.first;
            int y = q.top().second.second;
            q.pop();
            if(x==n-1 && y==m-1){
                return dist;
            }
            for (int i = 0; i < 4; i++) {
                int nrow = x + dr[i];
                int ncol = y + dc[i];
                if (nrow >= 0 and nrow < n and ncol >= 0 and ncol < m) {
                    int newDiff= max(dist,abs(heights[x][y]-ans[nrow][ncol]));
                    if(newDiff < ans[nrow][ncol]){
                        ans[nrow][ncol] = dist ;
                        q.push({dist, {nrow, ncol}});
                    }
                    
                }
            }
        }
        return 0;

    }
};