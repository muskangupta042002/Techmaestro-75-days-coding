class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> >ans;
        sort(nums.begin() , nums.end());
        int n=nums.size();
        for(int i=0;i<n-2;i++)
        {
            if(i==0 || (i>0 && nums[i]!=nums[i-1])){
            int j=i+1,k=n-1;
            while(j<k)
            {
                if(nums[i]+nums[j]+nums[k]==0)
                {
                    
                    ans.push_back({nums[i],nums[j],nums[k]});
                    while(j<k && nums[j]==nums[j+1])
                    {
                        j++;
                    }
                    while(j<k && nums[k]==nums[k-1])
                    {
                        k--;
                    }
                    j++;
                    k--;
                }
                else  if(nums[i]+nums[j]+nums[k]>0)
                {
                    k--;
                }
                else
                {
                    j++;
                }
            }
        }
        }
        return ans;
    }
};
