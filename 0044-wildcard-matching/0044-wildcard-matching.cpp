class Solution {
public:
    bool helper(int n, int m, string s, string p, vector<vector<bool>>& dp) {
        if (n == 0 && m == 0) {
            return true;
        }
        if (n > 0 && m < 0) {
            return false;
        }
        if (n == 0 && m > 0) {
            for (int i = 1; i <= m; i++) {
                if (p[i - 1] != '*') {
                    return false;
                }
            }
            return true;
        }
        if (dp[n][m] == true)
            return dp[n][m];
        if (s[n - 1] == p[m - 1] || p[m - 1] == '?') {
            return dp[n][m] = helper(n - 1, m - 1, s, p, dp);
        }
        if (p[m - 1] == '*') {
            return dp[n][m] = (helper(n - 1, m, s, p, dp) ||
                               helper(n, m - 1, s, p, dp));
        }
        return false;
    }
    bool isMatch(string s, string p) {
        if (p == "*") {
            return true;
        }
        int n = s.length(), m = p.length();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        // return helper(n-1,m-1,s,p,dp);
        dp[0][0] = true;
        for (int i = 1; i <= n; i++) {
            dp[i][0] = false;
        }
        for (int j = 1; j <= m; j++) {
            bool flag = true;
            for (int k = 1; k <= j; k++) {
                if (p[k - 1] != '*') {
                    flag = false;
                    break;
                }
            }
            dp[0][j] = flag;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                } else {
                    dp[i][j] = false;
                }
            }
        }
        return dp[n][m];
    }
};
/*
case1: ?, char*/