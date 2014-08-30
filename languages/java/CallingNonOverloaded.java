import java.util.ArrayList;

/**
 * Example 56 - Calling Non Overloaded, Non Overridden Methods
 */
class CallingNonOverloaded {

    static class SPoint {
        static ArrayList<SPoint> allpoints = new ArrayList<SPoint>();
        int x, y;

        SPoint(int x, int y) {
            allpoints.add(this);
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

        int getIndex() {
            return allpoints.indexOf(this);
        }

        static int getSize() {
            return allpoints.size();
        }

        static SPoint getPoint(int i) {
            return allpoints.get(i);
        }

    }

    public static void main(String[] args) {
        System.out.println("Number of points created: " + SPoint.getSize());
        SPoint p = new SPoint(12, 123);
        SPoint q = new SPoint(200, 10);
        SPoint r = new SPoint(99, 12);
        SPoint s = p;

        // Interesting
        q = null;

        System.out.println("Number of points created: " + SPoint.getSize());
        // Bad Style
        System.out.println("Number of points created: " + q.getSize());
        System.out.println("r is point number" + r.getIndex());
        for (int i = 0; i < SPoint.getSize(); i++)
            System.out.println("SPoint number " + i + " is " + SPoint.getPoint(i));
    }


}
