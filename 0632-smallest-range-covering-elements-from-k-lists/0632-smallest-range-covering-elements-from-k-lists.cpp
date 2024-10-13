class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int,int>> mp;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<nums[i].size();j++)
            {
                mp.push_back({nums[i][j],i});
            }
        }
        sort(mp.begin(),mp.end());
        int diff=nums.size();
        int v[diff];
        int total=0;
        int mini=1e9;
        int j=0;
        vector<int> ans;
        memset(v,0,sizeof(v));
        for(int i=0;i<mp.size();i++)
        {
            v[mp[i].second]++;
            if(v[mp[i].second]==1){total++;}
            if(total==diff)
            {
                if(mp[i].first-mp[j].first+1 < mini)
                {
                    mini=mp[i].first-mp[j].first+1;
                    ans={mp[j].first,mp[i].first};
                }
            }
            if(total==diff)
            {
                while(total==diff)
                {
                    if(v[mp[j].second]>1)
                    {
                        v[mp[j].second]--;
                        j++;
                    }
                    else
                    {
                        break;
                    }
                }
                if(mp[i].first-mp[j].first+1 < mini)
                {
                    mini=mp[i].first-mp[j].first+1;
                    ans={mp[j].first,mp[i].first};
                }
            }
        }
        return ans;
    }
};