/**
 * Example 59 - Calling Overridden and Overloaded Methods
 */
class C1 {
    static void m1(double d) {
        System.out.println("11d");
    }
    void m1(int i) {
        System.out.println("11i");
    }
    void m2(int i) {
        System.out.println("12i");
    }
}

class C2 extends C1 {
    static void m1(double d) {
        System.out.println("21d");
    }

    void m1(int i) {
        System.out.println("21i");
    }

    void m2(double d) {
        System.out.println("22d");
    }

    void m2(Integer ii) {
        System.out.println("22ii");
    }

    void m3(int i) {
        System.out.println("23i");
    }

    void m4(Integer ii) {
        System.out.println("24ii");
    }

}
class CallingOverriden {

    public static void main(String[] args) {
        int i = 17;
        Integer ii = new Integer(i);
        double d = 17.0;
        C2 c2 = new C2();
        C1 c1 = c2;
        c1.m1(i); c2.m1(i); c1.m1(d); c2.m1(d);
        c1.m2(i);
        c2.m2(i);
        c2.m2(ii);
        c2.m3(ii);
        c2.m4(i);
    }

}
