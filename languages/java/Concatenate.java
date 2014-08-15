/* javac Concatenate.java
   java arg1 arg2
   Output:
   arg1arg2
 */
class Concatenate {
  public static void main(String[] args) {
    String res = "";
    for(int i = 0; i < args.length; i++)
      res += args[i];
    System.out.println(res);
  }
}
