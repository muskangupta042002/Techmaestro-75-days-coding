class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& board, vector<vector<int>> &vis ){
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || vis[i][j]==1 || board[i][j]=='X'){
            return;
        }
        board[i][j]='P';
        vis[i][j]=1;
        dfs(i,j+1,board,vis);
        dfs(i-1,j,board,vis);
        dfs(i+1,j,board,vis);
        dfs(i,j-1,board,vis);
        
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            if(board[i][0]=='O'&& vis[i][0]!=1){
                dfs(i,0,board,vis);
            }
            if(board[i][n-1]=='O'&& vis[i][n-1]!=1){
                dfs(i,n-1,board,vis);
            }
        }
        for(int j=0;j<n;j++){
            if(board[0][j]=='O' && vis[0][j]!=1){
                dfs(0,j,board,vis);
            }
            if(board[m-1][j]=='O' && vis[m-1][j]!=1){
                dfs(m-1,j,board,vis);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='P'){
                    board[i][j]='O';
                }
                else{
                    board[i][j]='X';
                }
            }
        }
       // return board;
    }
};