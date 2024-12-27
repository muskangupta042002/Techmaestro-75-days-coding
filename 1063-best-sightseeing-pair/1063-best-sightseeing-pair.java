class Solution {
    public int maxScoreSightseeingPair(int[] values) {
        int n=values.length; System.out.println(n);
        int maxLeft=values[0], maxi=0;
        for(int i=1;i<n;i++){
            //for(int j=i+1;j<n;j++){
                
                maxi=Math.max(maxi, maxLeft+values[i]-i);
                maxLeft = Math.max(maxLeft, values[i]+i);
            //}
        }
        return maxi;
    }
}