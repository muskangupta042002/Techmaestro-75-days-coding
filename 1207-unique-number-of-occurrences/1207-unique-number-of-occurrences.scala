object Solution {
    def uniqueOccurrences(arr: Array[Int]): Boolean = {
        var mp=scala.collection.mutable.Map[Int,Int]()
        for(i<-arr){
            if(mp.contains(i)){
                mp(i)=mp(i)+1
            }
            else mp(i)=1
        }
        println(mp.mkString(", "))
        println(mp.values +" , "+ mp.size +", "+mp.values.toSet.size)
        if(mp.size == mp.values.toSet.size){
            return true
        }
        return false
    }
}
/**
Line 6: error: value update is not a member of scala.collection.immutable.Map[Int,Int] (in solution.scala)
did you mean updated?
                mp(i)=mp(i)+1
                ^
Line 8: error: value update is not a member of scala.collection.immutable.Map[Int,Int] (in solution.scala)
did you mean updated?
            else mp(i)=1
                 ^
Line 10: error: Int does not take parameters (in solution.scala)
        if(mp.size()==mp.keySet().size){
                  ^
Line 10: error: not enough arguments for method apply: (elem: Int): Boolean in trait SetOps. (in solution.scala)
Unspecified value parameter elem.
        if(mp.size()==mp.keySet().size){
                               ^**/