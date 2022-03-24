class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size(),zero=0;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(nums[i]==0)
            {
                zero++;
            }
        }
        if(sum<target)
        {
            return 0;
        }
        if((sum+target)%2!=0){
            return 0;
        }
        int s=(target+sum)/2;
        if(s<0)
        {
            return 0;
        }
        int dp[n+1][s+1];
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=1;
        }
        for(int i=1;i<=s;i++)
        {
            dp[0][i]=0;
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<s+1;j++)
            {
                if(nums[i-1]<=j )
                {
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-nums[i-1]];
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][s];
    }
};