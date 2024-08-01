class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<pair<int, int>> adj[n];
        for (int i = 0; i < flights.size(); i++) {
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }

        queue<pair<int, pair<int, int>>> q;
        vector<int> dist(n, 1e9);
        // vector<int> dis(n, 0);
        dist[src] = 0;
        // dis[src] = 0;
        q.push({0, {src, 0}});
        int sum = 1e9;
        while (!q.empty()) {
            int price = q.front().first;
            int node = q.front().second.first;
            int diff = q.front().second.second;
            q.pop();
            if (node == dst) {
                sum = min(sum, price);
            }
            if (diff <= k) {
                for (auto it : adj[node]) {

                    if (it.second + price < dist[it.first]) {
                        dist[it.first] = it.second + price;
                        // dis[it.first] = dis[node] + 1;
                            q.push({dist[it.first], {it.first,diff+1}});
                        }
                    }
                }
            }
            return sum == 1e9 ? -1 : sum;
        }
    };