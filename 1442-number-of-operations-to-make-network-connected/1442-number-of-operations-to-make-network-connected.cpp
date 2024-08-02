class Solution {
public:
    struct Node {
        int parent;
        int rank;
    };
    vector<Node> dsuf;

    int find(int v) {
        if (dsuf[v].parent == v) {
            return v;
        }
        return dsuf[v].parent = find(dsuf[v].parent); // path compression
    }

    void union_op(int fromP, int toP) {
        if (dsuf[fromP].rank > dsuf[toP].rank) {
            dsuf[toP].parent = fromP;
        } else if (dsuf[fromP].rank < dsuf[toP].rank) {
            dsuf[fromP].parent = toP;
        } else {
            dsuf[fromP].parent = toP;
            dsuf[toP].rank += 1;
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        int k = connections.size();
        if (k < n - 1) {
            return -1;
        }
        dsuf.resize(n);
        for (int i = 0; i < n; ++i) {
            dsuf[i].parent = i; // Each node is its own parent initially
            dsuf[i].rank = 0;   // Initial rank is 0
        }
        vector<pair<int, int>> edges;
        for (auto it : connections) {
            int u = it[0];
            int v = it[1];
            edges.push_back({u, v});
        }
        int count = 0;
        for (auto it : edges) {
            int u = it.first;
            int v = it.second;

            int fromP = find(u);
            int toP = find(v);
            if (fromP != toP) {
                
                union_op(fromP, toP);
            }
            else{
                count++;
            }
        }
        int c=0;
        for(int i=0;i<n;i++){
            if(dsuf[i].parent==i){
                c++;
            }
        }
        return c-1;
    }
};