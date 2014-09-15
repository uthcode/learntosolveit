import java.lang.reflect.Method;

/**
 * Example 157 - Listing Public Methods and Declared Methods
 */

class C1 {
    public int f1;
    protected int f2;
    public C1() {

    }
    public C1(int f1) {
        this.f1 = f1;
    }
    public void m1() {
        System.out.println("C1.m1()");
    }
    public void m1(int i) {
        System.out.println("C1.m1(int)");
    }

    private void m2() {
        System.out.println("C1.m2()");
    }
}

class C2 extends C1 {
    public void m3() {
        System.out.println("C2.m3()");
    }
    public void m4() {
        System.out.println("C2.m4()");
    }
}


class ReflectionPublicMethods {

    public static void main(String[] args) {
        Class<C2> c2o = C2.class;
        Method[] mop = c2o.getMethods();
        Method[] mod = c2o.getDeclaredMethods();
        for(Method m: mop)
            System.out.println(m.toString());
        for(Method m: mod)
            System.out.println(m.toString());
    }

}
