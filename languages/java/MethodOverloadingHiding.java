/**
 * Example 34 - Method Overloding, Overriding and Hiding
 */
public class MethodOverloadingHiding {
    static class C1 {
        void m1(double d) {
            System.out.println("11d");
        }
        void m1(int i) {
            System.out.println("11i");
        }
        void m2(int i) {
            System.out.println("12i");
        }
    }
    static class C2 extends C1 {
        void m1(double d) {
            System.out.println("21d");
        }
        void m1(int i) {
            System.out.println("21i");
        }
        void m2(double d) {
            System.out.println("22d");
        }
        void m3(Integer i) {
            System.out.println("22ii");
        }
        void m3(int i) {
            System.out.println("23i");
        }
        void m4(Integer ii) {
            System.out.println("24ii");
        }
    }

    public static void main(String[] args) {
        C1 o = new C1();
        o.m1(1.0);
        o.m1(1);
        o.m2(1);
        C2 o2 = new C2();
        o2.m1(1.0);
        o2.m1(1);
        o2.m2(1.0);
        o2.m3(1);
        o2.m3(1);
        o2.m4(2);
        o2.m2(1);
    }
}
