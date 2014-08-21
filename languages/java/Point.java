/**
 * Example 24 - Class Declaration
 */
public class Point {

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

    public static void main(String[] args) {
        Point p = new Point(10, 20);
        System.out.println(p);
    }

}
