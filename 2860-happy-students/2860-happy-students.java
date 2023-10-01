class Solution {
    public int countWays(List<Integer> nums) {
        int n=nums.size();
        int ans=0;
        Collections.sort(nums);
        if(nums.get(0)!=0){
            ans=1;
            
        }
        for(int i=0;i<n-1;i++){
            //sec++;
            if(i+1<n && i>=nums.get(i) && i+1<nums.get(i+1))
            {
                ans++;
            }
            
        }
        if(n-1>=nums.get(n-1))
            {
                ans++;
            }
        return ans;
    }
}