/**
 * Example 60 - Calling Overridden Methods from a Constructor
 */

class D1 {
    D1() {
        m2();
    }

    void m1() {
        System.out.println("D1.m1");
    }

    void m2() {
        System.out.println("D1.m2");
        m1();
    }
}

class D2 extends D1 {
    int f;
    D2() {
        f = 7;
    }

    void m1() {
        System.out.println("D2.m1: " + f);
    }
}

class CallingOverriddenConstructor {
    public static void main(String[] args) {
        D2 d2 = new D2();
        D1 d1 = new D1();
        d2.m1();
        d2.m2();
        d1.m1();
        d1.m2();
    }

}
