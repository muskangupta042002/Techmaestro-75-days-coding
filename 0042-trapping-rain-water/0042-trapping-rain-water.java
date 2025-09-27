class Solution {
    public int trap(int[] height) {
        int n=height.length;
        int[] pre=new int[n];
        int[] suf=new int[n];
        pre[0]=height[0];
        for(int i=1;i<n;i++){
            pre[i]=Math.max(height[i],pre[i-1]);
        }
        suf[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            suf[i]=Math.max(height[i],suf[i+1]);
        }
        int sum=0;
        for(int i=0;i<n;i++){
            if(height[i]<pre[i] && height[i]<suf[i]){
                 sum+=Math.min(suf[i],pre[i])-height[i];
            }
           
        }
        return sum;
    }
}