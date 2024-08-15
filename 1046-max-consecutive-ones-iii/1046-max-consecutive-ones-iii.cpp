class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int c = k, n = nums.size(), i = 0, j = 0;
        int maxi = 0, zero=0;
        while (j < n) {
            if (nums[j] == 0) {
                zero++;
                
            }
            if (zero<=k) {
                maxi = max(maxi, j - i + 1);
            } else {
                
                while(i<n && zero>k ){
                    if(nums[i++]==0){
                        zero--;
                    }
                }
            }
            j++;
        }
        return maxi;
    }
};