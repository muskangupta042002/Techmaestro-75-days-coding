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
        //vector<int> dp(n);
        int prev=nums[n-1],prev2=0;
        for(int i=n-2;i>=0;i--){
            int pick=nums[i];
            if(i<n-2){
                pick+=prev2;
            }
            prev2=prev;
            prev=max(pick,prev);
        }
        return prev;
    }
};