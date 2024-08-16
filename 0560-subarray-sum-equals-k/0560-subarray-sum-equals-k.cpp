class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0, sum = 0;
        unordered_map<int, int> mp;
        mp.insert({0, 1});
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (mp.find(sum - k) != mp.end()) {
                ans += mp[sum - k];
            }

            mp[sum]++;
        }
        
        return ans;
    }
};