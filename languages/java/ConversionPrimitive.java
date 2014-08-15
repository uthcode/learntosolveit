class ConversionPrimitive {
  private static void floatdouble(float f, double d) {
    System.out.println(f + " " + d);
  }
  private static void bytecharshort(byte b, char c, short s) {
    System.out.println(b + " " + (int) c + " " + s);
  }
  private static void intint(int i1, int i2) {
    System.out.println(i1 + " " + i2);
  }

  public static void main(String[] args) {
    int i1 = 1000111222, i2 = 40000, i3 = -1;
    floatdouble(i1, i1);
    bytecharshort((byte)i2, (char)i2, (short)i2);
    bytecharshort((byte)i3, (char)i3, (short)i3);
    intint((int)1.9, (int)-1.9);
    intint((int)1.5, (int)-1.5);
    intint((int)2.5, (int)-2.5);
  }
}
