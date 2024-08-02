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

    int removeStones(vector<vector<int>>& stones) {
        int maxRow=0, maxCol=0;
        int n=stones.size();
        for (auto it : stones) {
            int u = it[0];
            int v = it[1];
            maxRow=max(maxRow,u);
            maxCol=max(maxCol,v);
        }
        dsuf.resize(maxRow+maxCol+2);
        int count = 0;
        for (int i = 0; i < maxRow+maxCol+2; ++i) {
            dsuf[i].parent = i; // Each node is its own parent initially
            dsuf[i].rank = 0;   // Initial rank is 0
        }
        unordered_map<int,int>mp;
        for (auto it : stones) {
            int u = it[0];
            int v = it[1]+maxRow+1;
            if(find(u)!=find(v)){
                union_op(find(u), find(v));
                mp[u]=1;
                mp[v]=1;
            }
            
            
        }
        int c = 0;
        for (auto i: mp) {
            if (dsuf[i.first].parent == i.first) {
                c++;
            }
        }
        return n-c;
    }
};