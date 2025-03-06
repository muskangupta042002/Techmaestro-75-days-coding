object Solution {
    def findMissingAndRepeatedValues(grid: Array[Array[Int]]): Array[Int] = {
        val result = Array.ofDim[Int](2)
        result(0) = grid.flatten.groupBy(identity).filter(_._2.size == 2).keys.headOption.getOrElse(-1)
        val len = grid.length * grid.length
        val sum = (len * (len+1))/2
        result(1)=sum-grid.flatten.toSet.sum
        result
    }
}