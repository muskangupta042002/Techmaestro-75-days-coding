class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> adj[n+1];
        for (int i = 0; i < times.size(); i++) {
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        queue<pair<int, int>> q;
        vector<int> dist(n+1, 1e9);
        dist[k] = 0;
        q.push({0, k});
        int sum = -1;
        while (!q.empty()) {
            int price = q.front().first;
            int node = q.front().second;
            q.pop();

            for (auto it : adj[node]) {

                if (it.second + price < dist[it.first]) {
                    dist[it.first] = it.second + price;

                    q.push({dist[it.first], it.first});
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(dist[i]==1e9){
                return -1;
            }
            sum=max(sum,dist[i]);
        }
        return sum;
    }
};