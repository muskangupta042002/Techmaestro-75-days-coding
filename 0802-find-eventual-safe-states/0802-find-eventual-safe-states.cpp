class Solution {
public:
    bool checkCycle(int i, vector<vector<int>>& graph, vector<int> &vis, vector<int> &pathVis, vector<int> &check){
        vis[i]=1;
        pathVis[i]=1;
        check[i]=0;
        for(int k: graph[i]){
            if(!vis[k]){
                if(checkCycle(k,graph,vis,pathVis,check)) return true;
                
            }
            else if(pathVis[k]==1){
                return true;
            }
        }
        check[i]=1;
        pathVis[i]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //kind of adjacency list
        int V=graph.size();
        vector<int> vis(V,0);
        vector<int> pathVis(V,0);
        vector<int> check(V,0);
        vector<int> ans;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                checkCycle(i,graph,vis,pathVis,check);
            }
            
        }
        for(int i=0;i<V;i++){
            if(check[i]==1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};