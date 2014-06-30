public class Comments {
  //This is single line comment

  /*
  This is a multi-line comment, which can span across lines.
   */
  public static void main(String[] arg) {
    int /* The delimited comment can extend over a part of the line */ x = 42;
    System.out.printf("%d",x);
  }
}
