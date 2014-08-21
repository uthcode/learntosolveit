import java.util.ArrayList;

/**
 * Example 29 - Field Declarations
 */
public class FieldDeclarations {
    static ArrayList<FieldDeclarations> allfields = new ArrayList<FieldDeclarations>();
    int x, y;

    FieldDeclarations(int x, int y) {
        allfields.add(this);
        this.x = x;
        this.y = y;
    }

    public String toString() {
        return "(" + x + ", " + y + ")";
    }

    public static void main(String[] args) {
        FieldDeclarations fd = new FieldDeclarations(10, 20);
        FieldDeclarations fd2 = new FieldDeclarations(30, 40);
        for(FieldDeclarations f: allfields) {
            System.out.println(f);
        }
    }

}
