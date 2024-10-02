class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        
        int n=arr.size();
        vector<int> ans(n);
        unordered_map<int, vector<int>> mp;
        set<int> s;
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
            s.insert(arr[i]);
        }
        int i=1;
        for(auto it: s){
            // int num=it.first;
            // vector<int> values = it.second;
            int val=it;
            if(mp.find(val)!=mp.end()){
                for(int a: mp[val]){
                    ans[a]=i;
                    
                }
                i++;
            }
        }
        return ans;
    }
};