// In the Scala REPL, type 3 followed by the Tab Key. What
// methods can be applied?
// % - TODO skumaran - find usage
// &
// *
// +
// -
// /
// >
// >=
// >>
// >>>
//^
// asInstanceOf - TODO skumaran - find usage.
// isInstanceOf
// toByte
// toChar
// toDouble
// toFloat
// toInt
// toLong
// toShort
// toString
// unary_+
// unary_-
// unary_~
// | - TODO skumaran - find usage
// Question 2 - In the scala REPL, compute the square root
// of 3, and then square that value. By how much does the
// result differ from 3?
import scala.math._
val s = sqrt(3.0)
val d = s * s
3.0 - d // 4.440892098500626E-16
/**
 * Question 3:
 * Are the res variables val or var?
 *
 * Answer: They are val.
 */

// scala> sqrt(2.0)
// res39: Double = 1.4142135623730951
// scala> res39 = 10.1
// <console>:11: error: reassignment to val
//   res39 = 10.1


/**
 * Question 4:
 *
 *  Scala lets you multiply a string with a number - try out
 *  "crazy" * 3 in REPL.
 */

"crazy" * 3
// res1: String = crazycrazycrazy
// http://www.scala-lang.org/api/current/index.html#scala.collection.immutable.StringOps@*(n:Int):String

/**
 * Question 5:
 * What does 10 max 2 mean? n which class is the max method defined?
 *
 * Answer: Returns 2
 * It is defined in RichInt
 * http://www.scala-lang.org/api/current/index.html#scala.runtime.RichInt@max(that:Int):Int
 *
 */

10 max 2
/**
 * Question 6:
 * Using BigInt, compute 2 power 1024
 */

val two = BigInt(2)
two.pow(1024)
/**
 * Question 7:
 *
 * What do you need to import so that you can get a random prime as a
 * probablePrime(100, Random), without any qualifiers before probablePrime
 * and Random?
 *
 * import BigInt._
 * import scala.util._
 *  probablePrime(100, Random)
 */

import scala.BigInt._
import scala.util._
probablePrime(100, Random)
/**
 * Question 8:
 *
 * One way to create a random file or directory names is to produce a random BigInt
 * and convert it to base 36, yielding a string such as "qsnvxegege252dged".
 * Poke around Scaladoc to find a way of doing this in Scala.
 *
 * Random BigInt with number of bits set.
 * http://www.scala-lang.org/api/current/index.html#scala.math.BigInt$@apply(numbits:Int,rnd:scala.util.Random):scala.math.BigInt
 *
 * toString with a Radix
 * http://www.scala-lang.org/api/current/index.html#scala.math.BigInt@toString(radix:Int):String
 *
 */
BigInt(60, Random).toString(36)

/**
 * Question 9:
 *
 * How do you get the first character of a string in Scala? The last character?
 *
 * charAt method can be used to get the chars at position 0 and position length-1
 */

val str = BigInt(60, Random).toString(36)
str.charAt(0)
str.charAt(str.length-1)
str.take(1)
str.takeRight(1)


/**
 * Question 10:
 *
 * What do the take, drop, takeRight and dropRight string functions do?
 * What advantage or disadvantage do they have over using substring
 *
 * take, picks one character at a time from left and displays it
 * takeRight, picks up one character from the Right and prints it.
 *
 * drop, drops the specified number of characters and creates a new string.
 * dropRight, drops the specified number of characters to
 * the Right and creates a new string.
 *
 * The difference from substring is, the startindex is automatically provided.
 *
 */


val str2 = BigInt(60, Random).toString(36)
str2.charAt(0)
str2.charAt(str2.length-1)
str2.take(1)
str2.takeRight(1)
