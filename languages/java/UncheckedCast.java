/**
 * Example 111 - Unchecked Cast to Type Parameter
 */

class Hold<T> {
    private T contents;
    public void set(Object x) {
        contents = (T) x; // Unchecked cast
    }
    public T get() {
        return contents;
    }
}
class UncheckedCast {

    public static void main(String[] args) {
        Hold<Integer> h = new Hold<Integer>();
        h.set("foo"); // Succeeds at run-time
        System.out.println(h.get());

        // String s = h.get(); // Illegal, rejected by compiler
        //Integer i = h.get(); // Legal, but fails at run-time
    }

}
