class Solution {
public:
    int helper(int i, int buy, vector<int>& prices, vector<vector<int>>& dp,
               int fee) {
        int n = prices.size(); // Get the number of days

        // Base case: If we reach the end of the days, no more profit can be
        // made
        if (i >= n) {
            return 0;
        }

        // Return the result if it's already computed
        if (dp[i][buy] != -1) {
            return dp[i][buy];
        }

        int maxi;

        if (buy) {
            // We have the option to buy or skip
            maxi =
                max(-prices[i] +
                        helper(i + 1, !buy, prices, dp,
                               fee), // Buy the stock and move to the next day
                    helper(i + 1, buy, prices, dp, fee) // Skip this day
                );
        } else {
            // We have the option to sell or skip
            maxi = max(
                prices[i] + helper(i + 1, !buy, prices, dp, fee) -
                    fee, // Sell the stock and apply cooldown
                helper(i + 1, buy, prices, dp, fee) // Skip selling on this day
            );
        }

        // Store the result in the memoization table
        return dp[i][buy] = maxi;
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        // DP table to store the results for each state
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));

        // Start at day 0, with the option to buy
        // return helper(0, 1, prices, dp, fee);
        dp[n][0] = 0, dp[n][1] = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < 2; j++) {
                if (j) {
                    dp[i][j] = max(-prices[i] + dp[i + 1][!j], dp[i + 1][j]);
                } else {

                    dp[i][j] =
                        max(prices[i] + dp[i + 1][!j] - fee, dp[i + 1][j]);
                }
            }
        }
        return dp[0][1];
    }
};