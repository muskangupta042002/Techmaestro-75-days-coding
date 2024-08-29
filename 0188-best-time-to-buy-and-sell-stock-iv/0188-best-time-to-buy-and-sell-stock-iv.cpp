class Solution {
public:
int helper(int i, int buy, vector<int>& prices, vector<vector<vector<int>>>& dp, int count) {
        int n = prices.size();
        if (count == 0) {
            return 0;
        }
        if (i >= n ) {
            return 0;
        }
        if (dp[i][buy][count] != -1)
            return dp[i][buy][count];
        int maxProfit;
        if (buy) {
            int buying = -prices[i] + helper(i + 1, !buy, prices, dp, count);
            int notBuy = helper(i + 1, buy, prices, dp, count);
            maxProfit = max(buying, notBuy);
        } else {
            int sell = prices[i] + helper(i + 1, !buy, prices, dp, count-1);
            int notSell = helper(i + 1, buy, prices, dp, count);
            maxProfit = max(sell, notSell);
        }
        return dp[i][buy][count] = maxProfit;
    }

    int maxProfit(int k, vector<int>& prices) {
         int n = prices.size();
        if (n == 1)
            return 0;
        vector<vector<vector<int>>> dp(n ,vector<vector<int>>(2, vector<int>(k+1, -1) ));
        return helper(0,1,prices,dp,k);
    }
};