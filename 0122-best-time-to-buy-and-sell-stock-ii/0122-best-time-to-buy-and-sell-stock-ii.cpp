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
        if (n == 1)
            return 0;
        //vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        // return helper(0, 1, prices, dp);
        //dp[n][0] = 0, dp[n][1] = 0;
        vector<int> prev(2,0), curr(2,0);
        //prev[0]=0, prev[1]
        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy < 2; buy++) {
                if (buy) {
                    int buying = -prices[i] +prev[0];
                    int notBuy =  prev[1];
                    curr[buy] = max(buying, notBuy);
                } else {
                    int sell = prices[i] + prev[1];
                    int notSell = prev[0];
                    curr[buy] = max(sell, notSell);
                }
            }
            prev=curr;
        }
        return prev[1];
        // for (int i = n - 1; i >= 0; i--) {
        //     for (int buy = 0; buy < 2; buy++) {
        //         if (buy) {
        //             int buying = -prices[i] + dp[i+1][0];
        //             int notBuy =  dp[i+1][1];
        //             dp[i][buy] = max(buying, notBuy);
        //         } else {
        //             int sell = prices[i] + dp[i+1][1];
        //             int notSell = dp[i+1][0];
        //             dp[i][buy] = max(sell, notSell);
        //         }
        //     }
        // }
       // return dp[0][1];
    }
};