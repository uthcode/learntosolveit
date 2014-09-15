/**
 * Example 159 - Reflective Object Creation, Instance Tests and Casts
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

class ReflectiveObjectCreation {

    public static void main(String[] args) throws IllegalAccessException, InstantiationException {
        Class<C2> c2o = C2.class;
        C2 o2 = new C2();
        C1 o11 = new C1(), o12 = o2;
        C2 o21 = c2o.newInstance(); // well-typed: c2o has type Class<C2>
        System.out.println(c2o.isInstance(o12)); // true
        System.out.println(c2o.isInstance(o11)); // false
        C2 c22 = c2o.cast(o12); // succeeds at run-time: o12 can be cast to C2
        // C2 c23 = c2o.cast("foo"); // fails at run-time
    }
}
