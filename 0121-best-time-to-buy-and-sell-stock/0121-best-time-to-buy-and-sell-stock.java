class Solution {
    public int maxProfit(int[] prices) {
        int n=prices.length;
        int maxi=0,mini=prices[0];
        for(int i=1;i<n;i++){
            if(prices[i]>mini){
                maxi=Math.max(maxi, prices[i]-mini);
            }
            else{
                mini=prices[i];
            }
        }
        return maxi;
    }
}
/**

**/