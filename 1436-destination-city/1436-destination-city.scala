import scala.collection.mutable.Map
object Solution {
    def destCity(paths: List[List[String]]): String = {
        val mp: Map[String,String]=Map.empty[String,String]
        for(path <- paths){
            mp.put(path(0),path(1))
        }
        for((key, value) <- mp){
            if(!mp.contains(value)){
                return value;
            }
        }
        return "";
    }
}
/*
import scala.collection.mutable.Map

val emptyMutableMap: Map[String, Int] = Map.empty[String, Int]
import scala.collection.mutable.HashMap

val mp = new HashMap[String, String]()
val paths: List[List[String]] = /* Initialize paths with your data */

for (path <- paths) {
  mp.put(path(0), path(1))
}

for ((key, value) <- mp) {
  if (!mp.contains(value)) {
    return value
  }
}

""

*/