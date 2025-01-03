class Solution {
    public int waysToSplitArray(int[] nums) {
        int n=nums.length, sum=0;
        long[] pre = new long [n];
        long[] suff = new long[n];
        for(int i=0;i<n;i++){
            pre[i]=nums[i];
            suff[i]=nums[i];
            sum+=nums[i];
        }
        for(int i=1;i<n;i++){
            pre[i]+=pre[i-1];
        }
        for(int i=n-2;i>=0;i--){
            suff[i]+=suff[i+1];
        }
        int count=0;
        for(int i=0;i<n-1;i++){
            if(pre[i]>=suff[i+1]){
                count++;
            }
        }
        return count;
    }
}
