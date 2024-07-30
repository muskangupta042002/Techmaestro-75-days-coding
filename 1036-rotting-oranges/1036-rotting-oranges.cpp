class Solution {
public:
//, vector<bool>& visit
// void bfs(int x, int y, int m, int n, vector<vector<int>>& grid) {
//         queue<pair<int,int>> q;
//         q.push({x,y});
//         int drow[4]={-1,0,1,0};
//         int dcol[4]={0,1,0,-1};
//         //visit[x] = true;
//         while (!q.empty()) {
//             int row = q.front().first;
//             int col = q.front().second;
//             q.pop();
            
//             for (int i = 0; i < 4; i++) {
//                 if (grid[node][i] && !visit[i]) {
//                     q.push(i);
//                     visit[i] = true;
//                 }
//             }
//         }
//     }
    int orangesRotting(vector<vector<int>>& grid) {
        // int m=grid.size(), n=grid[0].size();
        // vector<bool> visit(n, false);
        // int count = 0;

        // for (int i = 0; i < m; i++) {
        //    for(int j=0;j<n;j++){
        //     if(grid[i][j]==2){
        //         bfs(i,j,m,n,grid);
                
        //     }
        //    }
        // }
        // return count;
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2 ){
                    q.push({{i,j},0});
                    vis[i][j]=true;
                }
            }
        }
        int drow[4]={-1,0,1,0};
        int dcol[4]={0,1,0,-1};
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int time=q.front().second;
            count=max(count,time);
            q.pop();
            for(int i=0;i<4;i++){
                int r=row+drow[i];
                int c=col+dcol[i];
                //check this always if use drow , dcol like things
                if(r>=0 && c>=0 && r<m && c<n && !vis[r][c] && grid[r][c]==1){
                    q.push({{r,c},time+1});
                    vis[r][c]=true;
                }
            }
            
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !vis[i][j]){return -1;}
            }
        }
        return count;
    }
};