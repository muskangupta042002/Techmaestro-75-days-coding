class Solution {
public:
    struct Node {
        int parent;
        int rank;
    };
    vector<Node> dsuf;

    int find(int v) {
        if (dsuf[v].parent == -1) {
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

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        // vector<bool> visit(n, false);
        int count = n;
        dsuf.resize(n);
        for (int i = 0; i < n; ++i) {
            dsuf[i].parent = -1; // Each node is its own parent initially
            dsuf[i].rank = 0;    // Initial rank is 0
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isConnected[i][j] && find(i) != find(j)) {
                    count--;
                    union_op(find(i),find(j) );
                }
            }
        }
        return count;
    }
};