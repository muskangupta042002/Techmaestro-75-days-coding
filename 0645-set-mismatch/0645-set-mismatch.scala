import scala.collection.mutable.Set
object Solution {
    def findErrorNums(nums: Array[Int]): Array[Int] = {
        val n=nums.size
        var x=new Array[Int](n)
        
        var a=0
        var b=0
        for(i <- 0 to n-1){
            x(nums(i)-1)=x(nums(i)-1)+1
        }
        for(i <- 0 to n-1){
            if(x(i)>1){
                a=i+1
            }
            else if(x(i)==0){
                b=i+1
            }
        }
        return Array(a,b)
    }
}