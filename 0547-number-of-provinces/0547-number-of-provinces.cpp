class Solution {
public:
    void dfs(int x,  int n, vector<vector<int>>& isConnected, vector<bool>& visit) {
        

        visit[x] = true;
        for(int i=0;i<n;i++){
            if(isConnected[x][i] && !visit[i]){
                dfs(i,n,isConnected,visit);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool>visit(n,false);
        int count=0;
        for(int i=0;i<n;i++){
            if(!visit[i]){
                     dfs(i, n, isConnected, visit);
                     count++;
                
            }
        }
        return count;
    }
};