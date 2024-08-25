class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m=grid.size(), n=grid[0].size();
        if(n==1 && m==1) return 0;
        queue<vector<int>> q;
        vector<vector<int>>vis(m,vector<int>(n,-1));
        //i,j,visited towns,coinsleft
        q.push({0,0,0,k});
        vis[0][0]=k;
        int count=0, mini=INT_MAX;
        while(!q.empty()){
            auto a=q.front();
            int coins=a[3];
            int towns=a[2];
            int row=a[0];
            int col=a[1];
            q.pop();
            int dx[4]={0,1,0,-1};
            int dy[4]={1,0,-1,0};
            if(row==m-1 && col==n-1){
                return towns;
            }
            if(grid[row][col]==1){
                if(!coins){
                    continue;
                }
                coins--;
            }
            for(int i=0;i<4;i++){
                int r=row+dx[i];
                int c=col+dy[i];
                if(r>=0 && r<m && c>=0 && c<n && vis[r][c]<coins){
                    q.push({r,c,towns+1,coins});
                    vis[r][c]=coins;
                }
            }
        }
        return -1;
    }
};