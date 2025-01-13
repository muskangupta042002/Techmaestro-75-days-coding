class Solution {
    public int minimumLength(String s) {
        Map<Character, Integer> mp=new HashMap<>();
        for(int i=0;i<s.length();i++){
            Character c=s.charAt(i);
            mp.put(c,mp.getOrDefault(c,0)+1);
        }
        int count=0;
        for(Map.Entry<Character,Integer> e: mp.entrySet()){
            if( e.getValue()%2!=0){
                count+=e.getValue()-1;
            }
            else{
                 count+=e.getValue()-2;
            }
        }
        return s.length()-count;
    }
}
/*
"abaacbcbb"
a

*/