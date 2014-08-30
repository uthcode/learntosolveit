/**
 * Example 57 - Parameter Passing Copies References, Not Objects and Arrays
 */
class ParameterPassing {

    public static class Point {

        int x, y;

        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        void move(int dx, int dy) {
            x += dx;
            y += dy;
        }

        public String toString() {
            return "(" + x + ", " + y + ")";
        }

    }

    static void m(Point pp, int dd, int[] aa) {
        pp.move(dd, dd);
        dd = 117;
        aa[3] = 22;
    }

    public static void main(String[] args) {
        Point p = new Point(10, 20);
        int[] a = new int[5];
        int d = 8;
        System.out.println("p is " + p);
        System.out.println("a[3] is " + a[3]);
        m(p, d, a);

        System.out.println("p is " + p);
        System.out.println("d is " + d);
        System.out.println("a[3] is " + a[3]);

    }
}
