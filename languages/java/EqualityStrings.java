class EqualityStrings {
  public static void main(String[] args) {
    String s1 = "abc";
    String s2 = s1 + "";
    String s3 = s1;
    String s4 = s1.toString();

    System.out.println("s1 and s2 identical objects: " + (s1 == s2));
    System.out.println("s1 and s3 identical objects: " + (s1 == s3));
    System.out.println("s1 and s4 identical objects: " + (s1 == s4));
    System.out.println("s1 and s2 contain same text: " + (s1.equals(s2)));
    System.out.println("s1 and s3 contain same text: " + (s1.equals(s3)));

    System.out.println(10 + 25 + "A");
    System.out.println("A" + 10 + 25);
  }
}
