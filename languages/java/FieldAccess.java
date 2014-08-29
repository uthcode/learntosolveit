/**
 * Example 53 - Field Access
 */
class FieldAccess {

    static class B {
        int vf;
        static int sf;

        B(int i) {
            vf = i;
            sf = i + 1;
        }
    }

    static class C extends B {
        int vf;
        static int sf;
        C(int i) {
            super(i+20);
            vf = i;
            sf = i + 2;
        }
    }

    static class D extends C {
        int vf;
        D(int i) {
            super(i + 40);
            vf = i;
            sf = i + 4;
        }
    }

    static void print(int x, int y) {
        System.out.println(x + " " + y);
    }

    static void print(int x, int y, int z) {
        System.out.println(x + " " + y + " " + z);
    }

    public static void main(String[] args) {

        C c1 = new C(100);
        B b1 = c1;
        print(C.sf, B.sf);
        print(c1.sf, b1.sf);
        print(c1.vf, b1.vf);
        C c2 = new C(200);
        B b2 = c2;

        print(c2.sf, b2.sf);
        print(c2.vf, b2.vf);
        print(c1.sf, b1.sf);
        print(c1.vf, b1.vf);

        D d3 = new D(300);
        C c3 = d3;
        B b3 = d3;

        print(D.sf, C.sf, B.sf);
        print(d3.sf, c3.sf, b3.sf);
        print(d3.vf, c3.vf, b3.vf);

    }
}
