class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        
        int n=nums.size();
        if(n%k!=0){
            return false;
        }
        map<int,int> mp;
        for(auto num:nums){
            mp[num]++;
        }

        int s=n/k;
        for(auto it: mp){
            if(it.second>0){
                for(int i=k-1;i>=0;--i){
                    //cout<<(mp[it.first+i]-=mp[it.first]);
                    if((mp[it.first+i]-=mp[it.first]) < 0){
                        return false;
                    }
                }
            }
        }
        return true;

    }
};