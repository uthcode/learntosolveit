import java.lang.reflect.Constructor;
import java.lang.reflect.InvocationTargetException;

/**
 * Example 162 - Reflective Creation of an Object
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

class ReflectiveCreation {

    public static void main(String[] args) throws NoSuchMethodException, IllegalAccessException, InvocationTargetException, InstantiationException {
        Class<C1> c1o = C1.class;
        Constructor<C1> cc1o = c1o.getConstructor(int.class); // Gets C1(int)
        Constructor cco = cc1o;
        C1 c11 = cc1o.newInstance(42); // Compile-time type C1
        System.out.println(c11.getClass().toString());
        Object c12 = cco.newInstance(56);  // Compile-time type Object
        System.out.println(c12.getClass().toString());
    }
}
