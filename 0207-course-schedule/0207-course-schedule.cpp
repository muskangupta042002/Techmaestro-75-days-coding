class Solution {
public:
    bool dfs(int i, vector<int>&vis, vector<int>&pathVis,  vector<int> adj[]){
        vis[i]=1;
        pathVis[i]=1;
        for(auto it: adj[i]){
            if(!vis[it]){
               if(dfs(it,vis,pathVis,adj)) return true;
            }
            else if(pathVis[i]==1){
                return true;
            }
        }
        pathVis[i]=0;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[v].push_back(u);
        }
        int V=numCourses;
        vector<int> indegree(V,0);
	    queue<int>q;
	    for(int i=0;i<V;i++){
	        for(auto it: adj[i]){
	           indegree[it]++;
	        }
	    }
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0){
	            q.push(i);
	        }
	    }
	    vector<int> ans;
	    while(!q.empty()){
	        int node=q.front();
	        q.pop();
	        ans.push_back(node);
	        for(auto it: adj[node]){
	            indegree[it]--;
	            if(indegree[it]==0){
	                q.push(it);
	            }
	        }
	    }
        if(ans.size()==numCourses){
            return true;
        }
        return false;
    }
};