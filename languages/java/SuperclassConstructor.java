/**
 * Example 37 - Calling a Superclass constructor
 */
class SuperclassConstructor {
    int x;
    int y;
    SuperclassConstructor(int x, int y)  {
        this.x = x;
        this.y = y;
    }

    public String toString() {
        return "(" + x + ", " + y + ")";
    }
}

class Subclass extends SuperclassConstructor{
    Subclass(int x, int y) {
        super(x, y);
    }

    public static void main(String[] args) {
        Subclass o = new Subclass(10, 20);
        System.out.println(o);
    }
}

