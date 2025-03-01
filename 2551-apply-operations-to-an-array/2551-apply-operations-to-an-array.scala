object Solution {
    def applyOperations(nums: Array[Int]): Array[Int] = {
       val processed =  nums.indices.foldLeft(nums.clone()){
            (acc, i) =>
                acc.toIndexedSeq.lift(i+1) match {
                    case Some(next) if acc(i)==next && acc(i)!=0 =>
                        acc.updated(i, acc(i)*2).updated(i+1,0)
                    case _ => acc

                }

        }
        val nonZero = processed.filter(_ != 0)
        nonZero ++ Array.fill(nums.length - nonZero.length)(0)

        
    }
}