class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        unordered_map<char,int>mp;
        for(int i=0;i<p.length();i++){
            mp[p[i]]++;
        }
        int j=0, i=0, k=p.length(),n=s.length(),count=mp.size();
        while(j<n){
            if(mp.find(s[j])!=mp.end()){
                mp[s[j]]--;
                if(mp[s[j]]==0){
                    count--;
                }}
                if(j-i+1 < k){
                    j++;
                }
                else if(j-i+1 == k){
                    if(count==0){
                        ans.push_back(j-k+1);
                    }
                    if(mp.find(s[i])!=mp.end()){
                        mp[s[i]]++;
                        if(mp[s[i]]==1){
                            count++;
                        }
                    }
                    i++;j++;
                }
                
            
            
        }
        return ans;
    }
};