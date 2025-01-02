class Solution {
    private boolean isVowel(char c1){
        if(c1=='a' || c1=='e' || c1=='i' || c1=='o' || c1=='u'){
            return true;
        }
        return false;
    }
    public int[] vowelStrings(String[] words, int[][] queries) {
        int n=queries.length;
        int[] ans= new int[n];
        int len = words.length;
        int[] vowels= new int[len];
        for(int i=0;i<len;i++){
            int l = words[i].length();
            if(isVowel(words[i].charAt(0)) && isVowel(words[i].charAt(l-1))){
                vowels[i]=1;
            }
            else{
                vowels[i]=0;
            }
        }
        for(int i=1;i<len;i++){
            vowels[i]+=vowels[i-1];
        }
        for(int i=0;i<n;i++){
            int c=queries[i][0]>0?vowels[queries[i][1]]-vowels[queries[i][0]-1]:vowels[queries[i][1]];
                
            ans[i]=c;
        }
        return ans;
    }
}
// 1 0 1 1 1
// 1 1 2 3 4
// 2 