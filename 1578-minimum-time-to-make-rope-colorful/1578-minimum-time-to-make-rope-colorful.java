class Solution {
    public int minCost(String colors, int[] neededTime) {
        int res = 0, n=colors.length();
        int start=0,end=0;
        while(start<n && end<n ){
            int groupSum=0,maxSum=0;
            while(end<n && colors.charAt(start)==colors.charAt(end)){
                maxSum=Math.max(neededTime[end],maxSum);
                groupSum+=neededTime[end];
                end++;
            }
            res+=groupSum-maxSum;
            start=end;
        }
        return res;
    }
}
/**
colors = "abaac", neededTime = [1,2,3,4,5]
Output: 3

sum=0 currMax=1
prev=a
sum=2 currMax=2 prev=b i=1
sum=3 currMax=3 prev=a i=2
sum=7 currMax=4 prev=a i=3
sum=8 currMax=5 prev=c i=4

**/