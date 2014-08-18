/**
 * Example 12 - Using a class that Declares a toString method
 */
class ToString {

    static class Point {
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

    public static void main(String[] args) {
        Point p1 = new Point(10, 20);
        Point p2 = new Point(30, 40);

        System.out.println("p1 is " + p1);
        System.out.println("p2 is " + p2);
        p2.move(7, 7);
        System.out.println("p2 is " + p2);

   }
}
