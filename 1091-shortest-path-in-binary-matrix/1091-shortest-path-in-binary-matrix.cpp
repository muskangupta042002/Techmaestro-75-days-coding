class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
           if(grid[0][0]==0 && n==1) return 1;
        pair<int,int> src{0,0};
    pair<int,int> dest{n-1,n-1};
    if(src.first==dest.first && src.second==dest.second && grid[src.first][src.second]==0) return 0;
    if(src.first==dest.first && src.second==dest.second && grid[src.first][src.second]==1) return -1;
    if(grid[src.first][src.second]==1 || grid[dest.first][dest.second]==1) return -1;
        vector<vector<int>> ans(n,vector<int>(n,1e9));
        
        ans[0][0] = 1;
        queue<pair<int,pair<int,int>>> q;
        q.push({1,{0,0}});
        int dr[] = {-1, 0, 1, 0,-1,1,1,-1};
        int dc[] = {0, 1, 0, -1,-1,1,-1,1};
        while(!q.empty()){
            int dist = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();
            for(int i=0; i<8; i++){
                int nrow = x + dr[i];
                int ncol = y + dc[i];
                if(nrow >= 0 and nrow < n and ncol >= 0 and ncol < n and grid[nrow][ncol] == 0 and dist + 1 < ans[nrow][ncol]) {
                    ans[nrow][ncol]=dist + 1;
                    q.push({dist + 1,{nrow,ncol}});
                }
            }
            
        }
        if(ans[n-1][n-1]==1e9) return -1;
        return ans[n-1][n-1];
    }
};