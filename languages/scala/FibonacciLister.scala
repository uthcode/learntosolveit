object FibonacciLister {
  def main(args: Array[String]) {
    val n = args(0).toInt
    var (a, b) = (0, 1)
    while (b <= n) {
      print(b + " ")
      var olda = a
      a = b
      b = a + b
    }
    println
  }
}
