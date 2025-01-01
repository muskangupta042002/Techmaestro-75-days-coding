class Solution {
    public int maxScore(String s) {
        int maxi=0;
        for(int i=0;i<s.length()-1;i++){
            int ones=0;
            int zeros=0;
            for(int j=0;j<=i;j++){
                if(s.charAt(j)=='0'){
                    zeros++;
                }
            }
            for(int j=i+1;j<s.length();j++){
                if(s.charAt(j)=='1'){
                    ones++;
                }
            }
            maxi=Math.max(maxi,zeros+ones);
        }
        return maxi;
    }
}