import scala.collection.mutable.Map
object Solution {
    def isAnagram(s: String, t: String): Boolean = {
        val mp=Map[Char,Int]();
        for(i <- 0 until s.length){
            if(mp.contains(s.charAt(i))){
                mp(s.charAt(i))+=1
            }
            else{
                mp(s.charAt(i))=1
            }
        }
        for(i <- 0 until t.length){
            if(mp.contains(t.charAt(i))){
                mp(t.charAt(i))-=1
            }
            else{
                return false
            }
        }
        for(i <- mp.values){
            if(i!=0){
                return false;
            }
        }
        return true
    }
}
/*
import scala.collection.mutable.Map

object Solution {
  def isAnagram(s: String, t: String): Boolean = {
    val mp = Map[Char, Int]()

    // Iterate over characters in the string s
    for (i <- 0 until s.length) {
      if (mp.contains(s.charAt(i))) {
        mp(s.charAt(i)) += 1
      } else {
        mp(s.charAt(i)) = 1
      }
    }

    // Iterate over characters in the string t
    for (i <- 0 until t.length) {
      if (mp.contains(t.charAt(i))) {
        mp(t.charAt(i)) -= 1
      } else {
        // If the character in t is not in the map, return false
        return false
      }
    }

    // Check if all values in the map are zero
    mp.values.forall(_ == 0)
  }

  def main(args: Array[String]): Unit = {
    val result = isAnagram("anagram", "nagaram")
    println(result)  // Should print: true
  }
}

*/
