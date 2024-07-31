class Solution {
public:
bool dfsCheck(int node, vector<int> adj[], vector<int>&vis, vector<int>&pathVis) {
		vis[node] = 1;
		pathVis[node] = 1;

		// traverse for adjacent nodes
		for (auto it : adj[node]) {
			// when the node is not visited
			if (!vis[it]) {
				if (dfsCheck(it, adj, vis, pathVis) == true)
					return true;
			}
			// if the node has been previously visited
			// but it has to be visited on the same path
			else if (pathVis[it]) {
				return true;
			}
		}

		pathVis[node] = 0;
		return false;
	}

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            for(auto it: graph[i]){
                adj[i].push_back(it);
            }
        }
        vector<int>vis(n,0), pathVis(n,0);
    vector<int> ans;
		for (int i = 0; i < n; i++) {
			if (!vis[i]) {
				dfsCheck(i, adj, vis, pathVis)  ;
			}
		}
        for(int i=0;i<n;i++){
            if(pathVis[i]==0){
                ans.push_back(i);
            }
        }
        sort(ans.begin(),ans.end());
		return ans;

    }
};