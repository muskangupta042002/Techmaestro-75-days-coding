class Solution {
public:
    void dfs(int node, vector<vector<int>>& isConnected, vector<bool>&vis){
        vis[node]=true;
        for(int i=0;i<isConnected.size();i++){
            if(isConnected[node][i]==1 && !vis[i]){
                dfs(i,isConnected,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int m=isConnected.size();
        int n=isConnected[0].size();
        int count=0;
        vector<bool>vis(m,false);
        for(int i=0;i<m;i++){
            if(!vis[i]){
                count++;
                dfs(i,isConnected,vis);
            }
        }
        return count;
    }
};