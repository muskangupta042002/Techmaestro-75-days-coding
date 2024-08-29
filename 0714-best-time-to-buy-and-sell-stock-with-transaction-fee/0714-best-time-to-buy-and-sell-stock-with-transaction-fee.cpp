class Solution {
public:
    int helper(int i, int buy, vector<int>& prices, vector<vector<int>>& dp, int fee) {
        int n = prices.size();  // Get the number of days
        
        // Base case: If we reach the end of the days, no more profit can be made
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
            maxi = max(
                -prices[i] + helper(i + 1, !buy, prices, dp, fee),  // Buy the stock and move to the next day
                helper(i + 1, buy, prices, dp, fee)                 // Skip this day
            );
        } else {
            // We have the option to sell or skip
            maxi = max(
                prices[i] + helper(i + 1, !buy, prices, dp, fee) - fee,   // Sell the stock and apply cooldown
                helper(i + 1, buy, prices, dp, fee)                 // Skip selling on this day
            );
        }
        
        // Store the result in the memoization table
        return dp[i][buy] = maxi;
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        
        // DP table to store the results for each state
        vector<vector<int>> dp(n, vector<int>(2, -1));
        
        // Start at day 0, with the option to buy
        return helper(0, 1, prices, dp, fee);
    }
};