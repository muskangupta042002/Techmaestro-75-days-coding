class Solution {
public:
    int minInsertions(string s) {
        string str1=s,str2=s;
        reverse(str2.begin(),str2.end());
        if(str1==str2){
            return 0;
        }
        
        int n=str1.length(), m=str2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<n+1;i++){
            for(int j=1;j<=m;j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return n-dp[n][m];
    }
};