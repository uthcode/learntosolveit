/**
 * Example 19 - Array Element Assignment Type Check at Run-Time
 */
public class ArrayAssignmentTypeCheck {

    public static void main(String[] args) {
        Number[] a = new Integer[10];
        Double d = new Double(3.14);
        Integer i = new Integer(117);
        Number n = i;
        a[0] = i;
        a[1] = n;
        // Results in a Runtime exception
        try {
            a[2] = d;
        } catch (ArrayStoreException e) {
            System.out.println("Caught an ArrayStoreException.");
        }
    }

}
