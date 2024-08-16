class Solution {
public:
    int helper(vector<int>& nums, int k){
        int i = 0, j = 0, odd = 0, ans = 0, n=nums.size();
        while (j < n) {
            if (nums[j] % 2 != 0) {
                odd++;
            }
            while (i<=j && odd > k) {
                if(nums[i]%2!=0){
                    odd--;
                }
                i++;
            }
            if (odd <= k) {
                ans+=(j-i+1);
            }
            
            j++;
        }
        
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), c = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0) {
                c++;
            }
        }
        if (c == n || (c < n && n - c < k)) {
            return 0;
        }
        return helper(nums,k) -helper(nums,k-1);
    }
};