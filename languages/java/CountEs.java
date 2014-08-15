/**
 * Example 10 Counting the Number of e's in a String.
 */
class CountEs {
  static int ecount(String s) {
    int ecount = 0;
    for (int i=0; i < s.length(); i++)
      if (s.charAt(i) == 'e')
        ecount++;
    return ecount;
  }

  public static void main(String[] args) {
    System.out.println(CountEs.ecount("elepantine"));
  }
}
