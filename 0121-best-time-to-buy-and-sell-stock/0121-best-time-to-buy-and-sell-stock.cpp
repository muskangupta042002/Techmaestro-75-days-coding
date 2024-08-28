class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int maxi = INT_MIN;
        int ans=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]<prices[i-1]){
                maxi=prices[i];
            }
            maxi=max(maxi,prices[i]);
            mini=min(mini,prices[i]);
            ans= max(ans, maxi-mini);
        }
        return ans;
    }
};