import java.lang.reflect.Field;

/**
 * Example 160 - Reflective Access to a Field
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

class ReflectiveAccessToField {

    public static void main(String[] args) throws NoSuchFieldException, IllegalAccessException {
        Class<C2> c2o = C2.class;
        Field f1o = c2o.getField("f1");
        C2 o2 = new C2();
        f1o.set(o2, 117); // Sets o2.f1 to 117
        System.out.format("Value of o2.f1 = %d%n ", f1o.get(o2)); // Gets o2.f1
        Class<C1> c1o = C1.class;
        Field f21 = c1o.getDeclaredField("f2");
    }
}
