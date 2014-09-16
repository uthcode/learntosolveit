/**
 * Exercises 6: Using BigInt compute 2 ^ 1024
 *
 */

import scala.math._

object ScalaBigInt extends Application {
  val res: BigInt = pow(2, 1024).toInt
  println(res)
}
