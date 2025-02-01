class Solution {
    public String findValidPair(String s) {
        int n=s.length();
        int[] arr=new int[10];
        for(int i=0;i<n;i++){
            arr[s.charAt(i)-'0']+=1;
        }
        for(int i=0;i<n-1;i++){
            int a=s.charAt(i)-'0';
            int b=s.charAt(i+1)-'0';
            if(a!=b && arr[a]==a && arr[b]==b){
                return s.substring(i, i+2);
            }
        }
        return "";
    }
}