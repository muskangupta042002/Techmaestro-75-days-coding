class Solution {
public:
    struct Node{
        int parent;
        int rank;
    };
    vector<Node> dsuf;

    int find(int v){
        if(dsuf[v].parent==v){
            return v;
        }
        return dsuf[v].parent=(find(dsuf[v].parent));
    }

    void union_ops(int fromU, int toV){
        if(dsuf[fromU].rank > dsuf[toV].rank){
            dsuf[toV].parent=fromU;
        }
        else if(dsuf[fromU].rank < dsuf[toV].rank){
            dsuf[fromU].parent=toV;
        }
        else{
            dsuf[fromU].parent=toV;
             dsuf[toV].rank+=1;
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        unordered_map<string,int>mp;

        sort(accounts.begin(),accounts.end());
        dsuf.resize(n);
        for (int i = 0; i < n; ++i) {
            dsuf[i].parent = i; // Each node is its own parent initially
            dsuf[i].rank = 0;   // Initial rank is 0
        }

        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if(mp.find(mail)!=mp.end()){
                    int fromU=(find(i));
                    int toV = find(mp[mail]);
                    union_ops(fromU, toV);
                }
                else{
                    mp[mail]=i;
                }
            }
        }

        vector<string> mergedMail[n];
        for(auto it:mp){
            string mail = it.first;
            int index = it.second;

            int node=find(index);
            mergedMail[node].push_back(mail);
        }


        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(mergedMail[i].size()==0) continue;
            sort(mergedMail[i].begin(),mergedMail[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto it:mergedMail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};