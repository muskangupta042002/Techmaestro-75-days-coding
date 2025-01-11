class Solution {
    public boolean canConstruct(String s, int k) {
        if(s.length()<k){
            return false;
        }
        int[] arr=new int[26];
        for(int i=0;i<s.length();i++){
            arr[s.charAt(i)-'a']++;
        }
int count=0;
        for(int i=0;i<26;i++){
            if(arr[i]%2==1){
                count++;
            }
            if(count > k){
                return false;
            }
        }
        System.out.println(count);
        int c=(s.length()-count)/2;
       System.out.println(c);
        return true;
    }
}
