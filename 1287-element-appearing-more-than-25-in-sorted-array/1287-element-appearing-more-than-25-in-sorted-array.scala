import scala.collection.mutable.Map
object Solution {
    def findSpecialInteger(arr: Array[Int]): Int = {
        var map=Map[Int,Int]()
        for(i <- arr){
            if(map.contains(i)){
                map(i)=map(i)+1
            }
            else{
                map(i)=1;
            }
        }
        val target=arr.length / 4;
        for((k,v) <- map){
            if(v>target) return k
        }
    return -1
    }
}
/**
 unordered_map<int, int> counts;
        for (int num : arr) {
            counts[num]++;
        }
        
        int target = arr.size() / 4;
        for (auto& [key, value] : counts) {
            if (value > target) {
                return key;
            }
        }
        
        return -1;
*/