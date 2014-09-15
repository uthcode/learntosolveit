import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

/**
 * Example 161 - Reflective Retrieval and Invocation of a Method
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

class ReflectiveRetrieval {

    public static void main(String[] args) throws NoSuchMethodException, InvocationTargetException, IllegalAccessException {
        Class<C1> c1o = C1.class;
        Method m1o  = c1o.getMethod("m1");
        Method m1io = c1o.getMethod("m1", int.class);
        C2 o2 = new C2();
        m1o.invoke(o2); // Call o2.m1()
        m1io.invoke(o2, 117); // Call o2.m1(117)

    }

}
