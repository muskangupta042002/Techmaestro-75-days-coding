class Solution {
    public boolean doesValidArrayExist(int[] derived) {
        int xor=0;
        for(int i=0;i<derived.length;i++){
            xor^=derived[i];
        }
        int n=derived.length;
        if(xor !=0) return false;
        return true;
    }
}
// 1 1 -> 1 0
// 1 0 -> 
// 0 1 ->
// 0 0 -> 