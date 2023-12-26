class Solution {
    int helper(int n, int k, int target, int[][] dp){
        if(n==0 && target==0){
            return 1;
        }
        if(target<=0 || n<=0){
            return 0;
        }
        if(dp[n][target]!=-1){
            return dp[n][target];
        }
        int count=0;
        for(int i=1;i<=k;i++){
            count=((count%1000000007)+(helper(n-1,k,target-i,dp)%1000000007))%1000000007;
            //count+=helper(1,6,2,0) -> helper(1,6,1,0) -> helper(1,6,0,0)
        }
         return dp[n][target]=count;
    }
    public int numRollsToTarget(int n, int k, int target) {
        int count=0;
        int[][] dp=new int[31][1001];
        for (int[] row : dp){
            Arrays.fill(row,-1);
        }
        
        count+=helper(n,k,target,dp);
        
        
        return count;
    }
}/*

-> n=1 always 1
count=1
               helper(1,6,3,0)
helper(1,6,2,0)
     helper(1,6,1,0)
     helper(1,6,0,0)
     
-> n=2 k=6 target=7
The states are how many dice are remaining, and what sum total you have rolled so far.


*/