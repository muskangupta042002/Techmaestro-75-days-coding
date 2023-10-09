class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxi = 0;
        int left = 0;
        int zero = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) zero++;
            if(zero<=k) maxi = max(maxi,(i-left+1));
            else while(left<nums.size() && zero>k) if(nums[left++]==0) zero--;
        }
        return maxi;
    }
};