/**
 * Example 52 - Object Creation and Instance Test
 */
public class ObjectCreation {
    public static void main(String[] args) {
        Number n1 = new Integer(17);
        Number n2 = new Double(3.14);

        System.out.println("n1 is a Double: " + (n1 instanceof Double));
        System.out.println("n2 is a Double: " + (n2 instanceof Double));
        System.out.println("null is a Double: " + (null instanceof Double));
        System.out.println("n2 is a Number: " + (n2 instanceof Number));
    }
}
