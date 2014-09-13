import java.util.Collection;
import java.util.LinkedHashMap;

/**
 * Example 129 - Iteration over an Iterable Collection
 */
class IterationOverIterable {

    public static void main(String[] args) {
        LinkedHashMap<String, String> m3 = new LinkedHashMap<String, String>();
        m3.put("map", "J");
        m3.put("dup", "K");
        m3.put("x", "M");
        m3.put("dup", "L");
        traverse(m3.keySet());
        traverse(m3.values());
    }

    static void traverse(Collection<String> coll) {
        for(String elem: coll)
            System.out.print(elem + " ");
        System.out.println();

    }
}
