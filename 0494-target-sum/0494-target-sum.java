class Solution {
    int count(int i, int[] nums, int target){
        
        if(target==0 && i>nums.length-1){
            return 1;
        }
        if(i>nums.length-1){
            return 0;
        }
        int left=target-nums[i];
        int right=target+nums[i];
        return count(i+1,nums,left) + count(i+1,nums,right);
    }
    public int findTargetSumWays(int[] nums, int target) {
        return count(0,nums,target);
    }
}
/*
2






4*/