object Solution {
    def maxProduct(nums: Array[Int]): Int = {
         var a=0
        var b=0;
        for(i <- nums){
            if(i>a){
                b=a;
                a=i
            }
            else if(i>b){
                b=i
            }
        }
         (a-1)*(b-1)
    }
}