/**
 * Example 11 Determining whether String occurs in Lexicographically increasing Order.
 */
public class Lexicographic {
  static boolean sorted(String[] a) {
    for(int i = 1; i < a.length; i++)
      if (a[i-1].compareTo(a[i]) > 0)
        return false;
    return true;
  }
  public static void main(String[] args) {
    String[] s = {"something", "verbose"};
    System.out.print(Lexicographic.sorted(s));
  }
}
