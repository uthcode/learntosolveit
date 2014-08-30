/**
 * Example 58 - Calling Overloaded Methods
 */
class CallingOverloaded {
    static class Access {
        private static int x;
        static class SI {
            private static int y = x; // Access private x from enclosing class
        }

        static void m() {
            int z = SI.y;             // Access private y from nested class
        }

        double m(int i) {
            return i;
        }
        boolean m(boolean b) {
            return !b;
        }

        static double m(int x, int y) {
            return x + y + 1;
        }

        static double m(double x, double y) {
            return x + y + 3;
        }
    }

    public static void main(String[] args) {
        Access a = new Access();
        System.out.println(Access.m(10, 20));
        System.out.println(Access.m(10, 20.0));
        System.out.println(Access.m(10.0, 20));
        System.out.println(Access.m(10.0, 20.0));
    }

}
