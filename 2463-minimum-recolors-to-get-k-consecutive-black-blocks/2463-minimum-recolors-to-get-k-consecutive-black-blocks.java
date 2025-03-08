class Solution {
    public int minimumRecolors(String blocks, int k) {
        int n=blocks.length();
        int b=0, w=0;
        int j=0;
        char start=blocks.charAt(0);
        for(int i=0;i<k;i++){
            if(blocks.charAt(i)=='B'){
                b++;
            }
            else{
                w++;
            }
        }
        if(b==k){
            return 0;
        }
        int maxB=w;
        for(int i=k;i<n;i++){
            if(blocks.charAt(i)=='B'){
                b++;
                if(blocks.charAt(j)=='B'){
                    b--;
                }
                else{
                    w--;
                }
                
            }
            else{
                w++;
                if(blocks.charAt(j)=='B'){
                    b--;
                }
                else{
                    w--;
                }
            }
            j++;
                maxB=Math.min(maxB,w);
        }
        return maxB;
    }
}