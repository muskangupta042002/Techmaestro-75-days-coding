class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        for(auto it: arr){
            
            mp[((it % k) + k) % k]++;
        }

        for(auto it: mp){
            int i=it.first;
            int val=it.second;
            cout<<it.first<<","<<it.second<<" ";
            if(i==0 && val%2==0){
                cout<<"j";
                continue;
            }
            if(mp.find(k-i)!=mp.end()){
                if(mp[k-i]!=mp[i]){
                    return false;
                }
            }
            else{
                return false;
            }
        }
        return true;
    }
};