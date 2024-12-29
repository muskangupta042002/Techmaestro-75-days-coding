class Solution {
    long helper(int targetIndex, int wordIndex,  String[] words, String target, int[][] dp, int[][] charfreq){
        if(targetIndex==target.length()){
            return 1;
        }
        if(wordIndex == words[0].length() || words[0].length()-wordIndex < target.length()-targetIndex ){
            return 0;
        }
        if(dp[wordIndex][targetIndex]!=-1){
            return dp[wordIndex][targetIndex];
        }
        long countWays = 0; int MOD = 1000000007;
        int pos = target.charAt(targetIndex)-'a';
        countWays+=helper(targetIndex,wordIndex+1,words,target,dp,charfreq);
        countWays+=charfreq[wordIndex][pos]*helper(targetIndex+1,wordIndex+1,words,target,dp,charfreq);
        return dp[wordIndex][targetIndex]=(int)(countWays % MOD);

    }
    public int numWays(String[] words, String target) {
        int wordLength=words[0].length(), targetLength=target.length();
        int[][] dp = new int[wordLength][targetLength];
        for(int i=0;i<wordLength;i++){
            Arrays.fill(dp[i],-1);
        }
        int[][] charFreq = new int[wordLength][26];

        for(String word: words){
            for(int i=0;i<word.length();i++){
                int c = word.charAt(i) - 'a';
                charFreq[i][c]++;
            }
        }
        return (int)helper(0,0,words,target,dp,charFreq);
    }
}