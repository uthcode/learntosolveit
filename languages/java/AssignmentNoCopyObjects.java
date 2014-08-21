/**
 * Example 49 - Assignment Does Not Copy Objects
 */
class AssignmentNoCopyObjects {

    static class Point {
        int x;
        int y;

        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        void move(int x1, int y1) {
            x += x1;
            y += y1;
        }

        public String toString() {
            return "(" + x + ", " + y + ")";
        }
    }

    public static void main(String[] args) {
        // TODO: Senthil Kumaran decouple Point
        Point p1 = new Point(10, 20);
        System.out.println("p1 is " + p1);
        Point p2 = p1;
        p2.move(8, 8);
        System.out.println("p2 is " + p2);
        System.out.println("p1 is " + p1);
    }

}
