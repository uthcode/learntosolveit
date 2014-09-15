import java.lang.reflect.Method;
import java.lang.reflect.Modifier;

/**
 * Example 163 - Reflective Inspection of Modifiers: static, private
 */


class ReflectiveInspection {

    static class C1S {
        public int f1;
        protected int f2;
        public C1S() {

        }
        public C1S(int f1) {
            this.f1 = f1;
        }
        public void m1() {
            System.out.println("C1.m1()");
        }
        public void m1(int i) {
            System.out.println("C1.m1(int)");
        }

        private static void m2() {
            System.out.println("C1.m2()");
        }
    }

    static class C2 extends C1S {
        private void m3() {
            System.out.println("C2.m3()");
        }
        private void m4() {
            System.out.println("C2.m4()");
        }
    }



    public static void main(String[] args) {
        Class<C2> c2o = C2.class;
        Method[] mod = c2o.getDeclaredMethods();
        for(Method m: mod)
            if (Modifier.isPrivate(m.getModifiers()))
                System.out.println(m.toString());
    }

}
