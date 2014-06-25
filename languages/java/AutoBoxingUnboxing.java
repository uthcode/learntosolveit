public class AutoBoxingUnboxing {

  public static void main(String[] args) {
    Boolean bb1 = false, bb2 = !bb1; // Boxing to false, true
    Integer bi1 = 117;
    Double bd1 = 1.2;
    boolean b1 = bb1;
    if (bb1)
      System.out.println("Not true");
    int i1 = bi1 + 2;
    // short s = bi1;
    long l = bi1;
    Integer bi2 = bi1 + 2;
    Integer[] biarr = {2, 3, 5, 7, 11};
    int sum = 0;
    for(Integer bi: biarr)
      sum += bi;
    for(int i: biarr)
      sum += i;
    int i = 1934;
    Integer bi4 = i, bi5 = i;

    // Prints true true true flase; bi4 == bi5 is a reference comparison
    System.out.format("%b %b %b %b\n", i==i, bi4==i, i==bi5, bi4==bi5);
    Boolean bbn = null;
    // boolean b = bbn; // compiles Okay but will fail at runtime
    // if (bbn)
    //  System.out.println("Not True");
    Integer bin = null;
    // Integer bi6 = bin + 2; // compiles Okay, but will fail at runtime
  }
}
