class Solution {
public:
    int helper(int i, int buy, vector<int>& prices, vector<vector<int>>& dp) {
        int n = prices.size();
        if (i >= n) {
            return 0;
        }
        if (dp[i][buy] != -1)
            return dp[i][buy];
        int maxProfit;
        if (buy) {
            int buying = -prices[i] + helper(i + 1, !buy, prices, dp);
            int notBuy = helper(i + 1, buy, prices, dp);
            maxProfit = max(buying, notBuy);
        } else {
            int sell = prices[i] + helper(i + 1, !buy, prices, dp);
            int notSell = helper(i + 1, buy, prices, dp);
            maxProfit = max(sell, notSell);
        }
        return dp[i][buy] = maxProfit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==1) return 0;
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return helper(0, 1, prices, dp);
        // dp[n]
        // for(int i=0;i<n;i++){

        // }
    }
};