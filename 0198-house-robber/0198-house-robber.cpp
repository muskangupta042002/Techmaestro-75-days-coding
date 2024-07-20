class Solution {
public:
    int helper(int ind, vector<int>& nums, int sum, vector<int>& dp) {
        
        if (ind >= nums.size()) {
            return sum;
        }
        if (dp[ind] != -1) {
            return dp[ind];
        }
        int l = helper(ind + 1, nums, sum, dp);
        int r = nums[ind]+helper(ind + 2, nums, sum , dp);

        return dp[ind] = max(l, r);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n);
        dp[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            int pick=nums[i];
            if(i<n-2){
                pick+=dp[i+2];
            }
            dp[i]=max(pick,dp[i+1]);
        }
        return dp[0];
    }
};