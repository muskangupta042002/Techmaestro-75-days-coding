class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size(), n=mat[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }

        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int time = q.front().second;
            q.pop();
            if(time>1){
                mat[row][col]=time;
            }
            int dx[4] = {0,1,-1,0};
            int dy[4] = {1,0,0,-1};
            for(int i=0;i<4;i++){
                int r=row+dx[i];
                int c=col+dy[i];
                if(r>=0 && c>=0 && r<m && c<n && vis[r][c]==0 && mat[r][c]==1){
                    q.push({{r,c},time+1}); vis[r][c]=true;
                }
            }
        }
        return mat;
    }
};