object Solution {
    def makeEqual(words: Array[String]): Boolean = {
        var n=words.length;
        //int[] conts=new int[26];
        var counts:Array[Int]=Array.fill(26)(0);
        for(word <- words){
            for(c <- word.toCharArray()){
                counts(c-'a')+=1;
            }
        }
        for(p <- counts){
            if(p % n!=0){
                return false;
            }
        }
        return true;
    }
}