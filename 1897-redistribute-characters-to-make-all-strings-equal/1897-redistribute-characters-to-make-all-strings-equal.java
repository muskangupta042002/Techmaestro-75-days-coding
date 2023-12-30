class Solution {
    public boolean makeEqual(String[] words) {
        int n=words.length;
        int[] counts=new int[26];
        for(String word: words){
            for(char c: word.toCharArray()){
                counts[c-'a']++;
            }
        }
        for(int val:counts){
            if(val % n!=0){
                return false;
            }
        }
        return true;
    }
}