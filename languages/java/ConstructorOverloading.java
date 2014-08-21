/**
 * Example 36 - Constructor Overloading; Calling Another Constructor
 */
class ConstructorOverloading {
    int x, y;

    ConstructorOverloading(int x, int y) {
        this.x = x;
        this.y = y;
    }

    ConstructorOverloading(ConstructorOverloading c) {
        this(c.x, c.y);
    }

    void incr(int x1, int y1) {
        x += x1;
        y += y1;
    }

    public String toString() {
        return "(" + x + ", " + y + ")";
    }

    public static void main(String[] args) {
        ConstructorOverloading c1 = new ConstructorOverloading(10, 20);
        c1.incr(40, 40);
        System.out.println(c1);
    }
}
