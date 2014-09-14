import java.util.Collection;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;

/**
 * Example 139 - Using Sets as Keys in a HashMap
 *
 * TODO: Senthil Kumaran - Program illustrates Complex types.
 * Write the complete Example.
 */
class SetsKeysinHashMap {

    static Map<Set<Integer>, Integer> mkRenamer(Collection<Set<Integer>> states) {
        Map<Set<Integer>, Integer> renamer = new HashMap<Set<Integer>, Integer>();

        for(Set<Integer> k: states)
            renamer.put(k, renamer.size());

        return renamer;
    }

    static Map<Integer, Map<String, Integer>> rename(Map<Set<Integer>, Integer> renamer,
                                                     Map<Set<Integer>, Map<String, Set<Integer>>> trans)  {
        Map<Integer, Map<String,Integer>> newtrans = new HashMap<Integer, Map<String, Integer>>();
        return newtrans;
    }
}
