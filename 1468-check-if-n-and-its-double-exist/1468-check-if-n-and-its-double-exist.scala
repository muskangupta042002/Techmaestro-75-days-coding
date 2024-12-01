object Solution {
  def checkIfExist(arr: Array[Int]): Boolean = {
    val sorted = arr.sorted
    sorted.indices.exists { i =>
      val target = 2 * sorted(i)
      sorted.indices.exists(j => j != i && sorted(j) == target)
    }
  }
}
