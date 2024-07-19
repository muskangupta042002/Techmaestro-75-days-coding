class Solution {
public:
    int helper(int ind, vector<int>& nums, int sum, vector<int>& dp) {
        
        if (ind >= nums.size()) {
            return 0;
        }
        if (dp[ind] != -1) {
            return dp[ind];
        }
        int l = helper(ind + 1, nums, sum, dp);
        int r = nums[ind]+helper(ind + 2, nums, sum , dp);

        return dp[ind] = max(l, r);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return helper(0, nums, 0, dp);
    }
};