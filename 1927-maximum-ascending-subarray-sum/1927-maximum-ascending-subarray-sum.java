class Solution {
    public int maxAscendingSum(int[] nums) {
        int sum=0,temp=nums[0];
        for(int i=1;i<nums.length;i++){
            if(nums[i-1]<nums[i]){
                temp+=nums[i];
            }
            else{
                sum=Math.max(sum,temp);
                temp=nums[i];
            }
        }sum=Math.max(sum,temp);
        return sum;
    }
}