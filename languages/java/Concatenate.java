/**
 * Example 9 Concatenating all Command Line Arguments.
 */

class Concatenate {
  public static void main(String[] args) {
    String res = "";
    for(int i = 0; i < args.length; i++)
      res += args[i];
    System.out.println(res);
  }
}
