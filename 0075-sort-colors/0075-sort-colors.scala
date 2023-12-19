object Solution {
    def sortColors(nums: Array[Int]): Unit = {
        var low=0
        var mid=0
        var high=nums.length-1
        while(mid<=high){
            if(nums(mid)==0) {
                var k=nums(mid)
                nums(mid)=nums(low)
                nums(low)=k
                low+=1
                mid+=1
            }
            else if(nums(mid)==1) mid+=1
            else {
                var k=nums(mid)
                nums(mid)=nums(high)
                nums(high)=k
                high-=1
            }
        }
    }
}