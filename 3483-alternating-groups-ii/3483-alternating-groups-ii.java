class Solution {
    public int numberOfAlternatingGroups(int[] colors, int k) {
        int n=colors.length;
        int ans=0,temp=1;
        int prev=colors[0];
       // int i=0,j=0;

        for(int i=1;i<n+k-1;i++){
            int index=i%n;
            if(colors[index] == prev){
                prev=colors[index];
                temp=1;
                continue;
            }
            temp+=1;
            if(temp>=k){
                ans++;        
            }
            prev=colors[index];
        

        }
        return ans;
    }
}