class Solution {
    public boolean helper(int n, int k, long mid, int budget, List<List<Integer>> composition, List<Integer> stock, List<Integer> cost){
        long minCost=Integer.MAX_VALUE;
        for(int i=0;i<k;i++){
            long currCost=0;
            for(int j=0;j<n;j++){
                long curr=mid*composition.get(i).get(j);
                if(stock.get(j)>=curr){
                    continue;
                }
                else{
                    long extra=(curr-stock.get(j))*cost.get(j);
                    currCost+=extra;
                }
            }
            minCost=Math.min(minCost,currCost);
        }
        return minCost<=budget;
    }
    
    public int maxNumberOfAlloys(int n, int k, int budget, List<List<Integer>> composition, List<Integer> stock, List<Integer> cost) {
        long low=0,high=(long)1e9;
        long ans=0;
        while(low<=high){
            long mid=(low+high)/2;
            if(helper(n,k,mid,budget,composition,stock,cost)){
                ans=mid;
                 low=mid+1;
            }
            else{
               
                high=mid-1;
            }
        }
        return (int)ans;
    }
}