class Solution {
public:
    int helper(vector<int>& nums, int goal){
        if (goal < 0)
            return 0;

        int ans = 0, n = nums.size();
        int left = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];

            while (sum > goal) {
                sum -= nums[left++];
            }
            if (sum <= goal) {
                ans += (i - left + 1);
            }
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return helper(nums,goal)-helper(nums,goal-1);
    }
};