import java.util.*;

/**
 * Example 138 - A Worklist Algorithm
 */
class WorklistAlgorithm {

    static <T> Set<Set<T>> intersectionClose(Set<Set<T>> ss) {
        LinkedList<Set<T>> worklist = new LinkedList<Set<T>>(ss);
        Set<Set<T>> tt = new HashSet<Set<T>>();

        while (!worklist.isEmpty()) {
            Set<T> s = worklist.removeLast();
            for(Set<T> t: tt) {
                Set<T> ts = new TreeSet<T>(t);
                ts.retainAll(s);

                if (!tt.contains(ts))
                    worklist.add(ts);
            }
            tt.add(s);
        }
        return tt;
    }

    public static void main(String[] args) {
        Set<Integer> s1 = new HashSet<Integer>(Arrays.asList(2, 3));
        Set<Integer> s2 = new HashSet<Integer>(Arrays.asList(1, 3));
        Set<Integer> s3 = new HashSet<Integer>(Arrays.asList(1, 2));
        Set<Set<Integer>> ss = new HashSet<Set<Integer>>(Arrays.asList(s1, s2, s3));

        Set<Set<Integer>> tt = intersectionClose(ss);

        for (Set<Integer>t: tt) {
            System.out.println(t.toString());
        }
    }
}
