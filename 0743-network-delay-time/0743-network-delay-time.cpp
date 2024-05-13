class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(int i=0;i<times.size();i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
            
        }
       priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        
         vector<int>dist(n+1,1e9);
        
        dist[k]=0;
        q.push({0,k});
        while(!q.empty()){
            auto it=q.top();
            q.pop();
            int sum=it.first;;
            int node=it.second;
            //int diff=
            
            for(auto a: adj[node]){
                
                if(dist[a.first]>sum+a.second){
                    dist[a.first]=sum+a.second;
                    q.push({sum+a.second,a.first});
                }
            }
        }
        int maxi=INT_MIN;
        for(int i=1;i<=n;i++){
            if(dist[i]==1e9){
                return -1;
            }
            else{
                maxi=max(maxi,dist[i]);
            }
        }
        return maxi;

    }
};