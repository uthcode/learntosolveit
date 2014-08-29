import java.util.ArrayList;

/**
 * Example 55 - Using this to Pass the Current Object to a Method
 */
public class UsingthisObject {
    static ArrayList<UsingthisObject> allpoints = new ArrayList<UsingthisObject>();
    int x, y;

    UsingthisObject(int x, int y) {
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

    public static void main(String[] args) {
        UsingthisObject o = new UsingthisObject(10, 20);
        System.out.println(o.getIndex());
    }
}
