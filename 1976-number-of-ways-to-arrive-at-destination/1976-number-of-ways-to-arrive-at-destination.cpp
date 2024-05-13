
#define MOD 1000000007 
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n];
        for(int i=0;i<roads.size();i++){
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
       priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> q;
        
         vector<long long>dist(n,1e15);
        vector<long long>ways(n,0);
        ways[0]=1;
        dist[0]=0;
        q.push({0,0});
        while(!q.empty()){
            auto it=q.top();
            q.pop();
            long long dis=it.first;;
            int node=it.second;
            
            for(auto a: adj[node]){
                
                if(dist[a.first] > (dis + a.second)){
                    dist[a.first]=(dis + a.second);
                    ways[a.first]=ways[node];
                    q.push({dist[a.first],a.first});
                }
                else if(dist[a.first] == (dis + a.second)){
                    ways[a.first]=(ways[a.first] + ways[node])%MOD ;
                }
            }
        }
        
        return ways[n-1]%MOD;
    }
};