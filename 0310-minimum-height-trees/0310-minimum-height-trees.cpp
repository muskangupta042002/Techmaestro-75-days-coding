class Solution {
public:
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1){
            return {0};
        }
        vector<int> ans;
        vector<int> adj[n];
        for(auto it: edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);

        }
        vector<int> leaves;
        for(int i=0;i<n;i++){
            int s=adj[i].size();
            if(s==1){
                leaves.push_back(i);
            }
        }
        
        while(n>2){
            n-=leaves.size();
            vector<int> newLeaves;
            for(int leaf: leaves){
                int nextNode = *(adj[leaf].begin());
                std::erase(adj[nextNode],leaf);
                if(adj[nextNode].size()==1){
                    newLeaves.push_back(nextNode);
                }
            }
            leaves=newLeaves;
        }
        return leaves;
    }
};