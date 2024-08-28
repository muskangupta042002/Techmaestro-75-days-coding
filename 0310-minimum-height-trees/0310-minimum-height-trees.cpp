class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            return {0};
        }
        
        vector<int> adj[n];
        vector<int> indegree(n, 0);
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            indegree[u]++;
            indegree[v]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 1)
                q.push(i), indegree[i]--;
        }
        vector<int> ans;
        while (!q.empty()) {
            int s = q.size();
            ans.clear();
            for (int i = 0; i < s; i++) {
                int curr = q.front();
                q.pop();
                ans.push_back(curr);
                for (auto child : adj[curr]) {
                    indegree[child]--;
                    if (indegree[child] == 1) {
                        q.push(child);
                    }
                }
            }
        }
        return ans;
        // vector<int> leaves;
        // for(int i=0;i<n;i++){
        //     int s=adj[i].size();
        //     if(s==1){
        //         leaves.push_back(i);
        //     }
        // }

        // while(n>2){
        //     n-=leaves.size();
        //     vector<int> newLeaves;
        //     for(int leaf: leaves){
        //         int nextNode = *(adj[leaf].begin());
        //         std::erase(adj[nextNode],leaf);
        //         if(adj[nextNode].size()==1){
        //             newLeaves.push_back(nextNode);
        //         }
        //     }
        //     leaves=newLeaves;
        // }
       // return leaves;
    }
};