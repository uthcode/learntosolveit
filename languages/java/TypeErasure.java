/**
 * Example 119 - Implementation of Type Erasure
 */

class Hold {
    private Object contents;
    public void set(Object x) {
        contents = x;
    }
    public Object get() {
        return contents;
    }
}
class TypeErasure {

    public static void main(String[] args) {
        Hold h = new Hold();
        h.set("foo");
        h.get();
        // Integer i = (Integer) h.get(); // Legal, but fails at run-time
    }
}
