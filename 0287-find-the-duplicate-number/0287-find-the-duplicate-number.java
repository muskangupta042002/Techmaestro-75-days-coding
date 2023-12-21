class Solution {
    public int findDuplicate(int[] nums) {
        int n=nums.length;
        for(int i=0;i<n;i++){
            int idx=Math.abs(nums[i]);
            if(nums[idx]<0){
                return idx;
                
            }
            nums[idx]=-nums[idx];
        }
        return n;
    }
}
/**
Input: nums = [1,3,4,2,2]
Output: 2
i=0 [1,-3,4,2,2]
i=1 [1,-3,4,2,2]
nums[nums[i]]


**/