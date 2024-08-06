class Solution {
public:
    int helper(int ind, int prev_ind, int n, vector<int>& nums, vector<vector<int>>&memo){
        if(ind>=n){
            return 0;
        }
        if(memo[ind][prev_ind+1]!=-1) return memo[ind][prev_ind+1];
        int take=0;
        if(prev_ind==-1 || nums[ind]%nums[prev_ind]==0){
            helper(ind+1,ind,n,nums,memo);    
        }
        int notTake=helper(ind+1,prev_ind,n,nums,memo);
        return memo[ind][prev_ind+1]=max(take,notTake);
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        //vector<vector<int>> ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        //  vector<vector<int>> memo(nums.size(), vector<int>(nums.size() + 1, -1));
        // return helper(0,-1,n,nums,memo); 
        vector<int> dp(n,1), par(n,1);

        for(int i=0;i<n;i++){
            par[i]=i;
            for(int prev_ind=0;prev_ind<=i-1;prev_ind++){
                if(nums[i]%nums[prev_ind] == 0 && 1+dp[prev_ind]>dp[i]){
                    dp[i]=1+dp[prev_ind];
                    par[i]=prev_ind;
                }
            }
        }
        int ans=-1, index=-1;
        for(int i=0;i<n;i++){
            if(dp[i]>ans){
                ans=dp[i];
                index=i;
            }
        }
        vector<int> temp;
        temp.push_back(nums[index]);
        while(par[index]!=index){
            index=par[index];
            temp.push_back(nums[index]);

        }
        reverse(temp.begin(), temp.end());

    return temp;
    }
};