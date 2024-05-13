class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
            
        }
       priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> q;
        //int n=flights.size();
        
         vector<int>dist(n,1e9);
        // vector<int> par(n,0);
        // for(int i=0;i<n;i++){
        //     par[i]=i;
        // }
        dist[src]=0;
        q.push({0,{src,0}});
        while(!q.empty()){
            auto it=q.top();
            q.pop();
            int sum=it.second.second;
            int node=it.second.first;
            int diff=it.first;
            
            for(auto a: adj[node]){
                
                if(diff<=k && dist[a.first]>sum+a.second){
                    dist[a.first]=sum+a.second;
                    q.push({diff+1,{a.first,sum+a.second}});
                }
            }
        }
        if(dist[dst]!=1e9) return dist[dst];
        return  -1;

    }
};
